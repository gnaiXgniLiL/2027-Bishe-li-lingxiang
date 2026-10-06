# 问题记录

## #1 custom-0 指令 load-use 冒险缺陷（上游框架）— 已规避，待根治

- **状态**：工作中规避已验证；proc.v 硬件修复待做
- **发现日期**：2026-10-06
- **现象**：conv3x3 CFU 版对拍 5/36，错误呈"行冻结"——第 0 行全对，
  其余每行结果精确等于第 0 行对应列
- **定位过程**：
  1. 排除除法假设（CFU 版消去除法仍失败；纯 C 版加除法仍正确）
  2. 探针 T1/T2（custom-0 直读刚加载的值）复现；E1（纯 C 对照）正常
  3. T3/T4 探针确认：lw 与 custom-0 之间隔 ≥1 条指令即正确
  4. 源码定位：proc.v 的 If_load_muldiv_use 对 load-use 仅停一拍，
     CFU 只被列入"生产者"一侧；lw 数据经同步 RAM 晚一拍返回，
     custom-0 作消费者紧跟 lw 时读到旧值
- **规避方案**：CFU 代码采用预加载+展开结构（load 全部在 CFU 序列之前完成）；
  CFU_OP 宏前置 nop 双保险（当前每条 CFU 指令 +3 拍）
- **待办**：修改 proc.v hazard 逻辑将 custom-0 纳入 load-use 停顿，
  去除 nop 税（候选：方案 B 阶段实施）

## #2 -O0 下内联汇编编译失败 — 已修复

- **现象**：`impossible constraint in 'asm'`
- **根因**：funct3 走 "i" 立即数约束，依赖编译器内联+常量传播，-O0 不内联
- **修复**：CFU_OP 改为宏字符串化（#f3 直接拼进指令文本），全优化级别兼容

## #3 程序映像固化导致"假结果" — 已知悉，流程规避

- **现象**：改 main.c 后 make run 结果不变
- **根因**：程序经 initf 生成 memi/memd.txt 后在 Verilate 时编进仿真器；
  make run 不触发重编译
- **规避**：改程序后必须 `make`（prog+build）再 `make run`