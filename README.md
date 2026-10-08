# 2027届本科毕业论文

## 基本信息

- 姓名：李凌翔
- 学号：202305100113
- 专业：人工智能
- 指导教师：曾维
- 毕业论文题目：面向轻量级CNN推理的RISC-V自定义MAC加速单元设计与优化
- 研究方向：RISC-V体系结构、AI硬件加速

## 一、研究问题

该研究对象为基于东京科学大学吉瀬研开源的 CFU-Proving-Ground 框架及其 RISC-V 自定义功能单元在轻量级 CNN 推理中的应用，基于框架现有 RV32IM 软核和 CFU 接口实现硬件加速。
当前轻量级 CNN 中卷积等算子包含大量 MAC 运算，采用软核执行时存在计算效率较低的问题，而如何利用 RISC-V 自定义功能单元对特定计算进行硬件加速，需要结合实际实现进行验证和性能分析。
该研究拟基于 CFU-Proving-Ground 设计并实现自定义 MAC 加速单元，将其接入现有 RV32IM 软核，并应用于卷积算子及小型 CNN 推理，通过 RTL 仿真、正确性验证和 Vivado 综合，比较软件实现与不同硬件方案在计算周期和硬件资源方面的差异。

## 二、最低完成要求

- [x] **Baseline / 基础系统**（2026-10-06 完成）
  - [x] 基于 CFU-Proving-Ground 现有 RV32IM 软核建立可运行的实验环境
  - [x] 实现纯软件 MAC / 卷积 Baseline
  - [x] 使用 RISC-V 工具链编译并运行
  - [x] 完成软件方案的 cycle 数统计
  - [x] 对比不同编译优化级别（-O0 / -Os / -O2 三级对照）

- [ ] **核心方法或关键机制**
  - [x] 理解并使用现有 CFU 接口
  - [x] 设计并实现 RISC-V 自定义 MAC 指令对应的 CFU
  - [x] 完成 MAC 数据通路、累加寄存器及必要的时序控制
  - [x] 完成 CFU RTL 仿真
  - [x] 将自定义 MAC 接入至少一个卷积算子（conv3x3 kernel，算子级）
  - [ ] 在小型 CNN 上完成端到端推理（进行中，见第五节）

- [ ] **对比实验**
  - [x] 软件 MAC / 卷积 Baseline
  - [x] CFU 单 MAC 方案
  - [ ] CFU 优化方案（方案 B，待设计）
  - [x] 对比不同方案的 cycle 数（算子级）
  - [ ] 分别统计卷积算子级和整网级性能（算子级已完成，整网级进行中）
  - [x] 计算相对加速比

- [ ] **消融 / 性能测试**
  - [ ] 完成至少一种明确的硬件优化方案
  - [ ] 比较不同设计方案的性能差异
  - [ ] 完成 Vivado 综合（进行中，见第五节）
  - [ ] 统计 LUT、FF、DSP、BRAM、Fmax 等指标
  - [ ] 分析硬件资源与计算性能之间的权衡

- [x] **错误或异常情况分析**
  - [x] 软件参考结果与 CFU 结果逐位比对
  - [x] 分析 RTL 仿真中的功能错误及边界情况（上游 custom-0 load-use 冒险缺陷，详见 progress/issues.md）
  - [x] 分析软件与硬件结果不一致的原因
  - [x] 分析不同方案可能存在的性能瓶颈和资源开销

- [ ] **完整毕业论文**
  - [x] 完成相关研究与技术背景（文献核验 18 篇、核心 13 篇、精读 6 篇）
  - [ ] 完成系统设计与实现
  - [ ] 完成功能验证与实验
  - [ ] 完成性能及资源分析
  - [ ] 完成结论与不足分析

## 三、拓展目标

- [ ] **FPGA 实板运行**
  - [ ] 将完成验证的 CFU 方案部署至 Nexys A7-100T
  - [ ] 完成实板端到端 CNN 推理验证

- [ ] **MAC 并行化**
  - [ ] 实现 2/4 路 MAC 并行
  - [ ] 比较不同并行度下的 cycle、资源占用和吞吐率
  - [ ] 分析并行度提升带来的资源与性能权衡

- [ ] **INT8 Packed MAC**
  - [ ] 实现基于 INT8 数据的 Packed MAC
  - [ ] 比较普通 MAC 与 Packed MAC 的计算效率和硬件资源
  - [ ] 在卷积算子或小型 CNN 上验证加速效果

- [ ] **进一步性能优化**
  - [ ] 探索 MAC 数据通路的流水线设计
  - [ ] 分析存储访问、数据搬运等潜在性能瓶颈
  - [ ] 根据实验结果优化 CFU 的指令接口或数据通路

- [ ] **扩展实验**
  - [ ] 比较不同 MAC 并行度或数据位宽下的性能
  - [ ] 绘制资源—性能权衡图
  - [ ] 分析不同硬件方案的适用场景

## 四、技术路线

**技术路线**

CFU-Proving-Ground 现有 RV32IM 软核
→ 现有 CFU 接口
→ 纯软件 MAC/卷积 Baseline
→ 自定义 MAC CFU 设计与 RTL 实现
→ RTL 仿真与正确性验证
→ 接入卷积算子
→ 小型 CNN 端到端推理
→ 与软件 Baseline 进行 cycle / 加速比对比
→ 实现优化方案
→ Vivado 综合与资源、性能分析
→ Nexys A7-100T 实板验证（拓展）

详细技术路线见：[技术路线详细说明](docs/01-topic/technical_route.md)。

## 五、当前进展

**当前阶段（2026-10-07 更新）：**

老师布置的五项任务（仓库初始化 / 文献核验 / Baseline 跑通 / 实验设计文档 /
Baseline 与问题分析报告）已全部完成，11 月底硬节点（软件 Baseline + 单 MAC 仿真）
提前约两个月达成。2026-10-07 老师检查仓库后给出四项下一阶段任务，
当前按以下顺序推进：

1. 修复 proc.v hazard 逻辑、去除 3 nop 保险，重新测量 dot256 + conv3x3；
2. 补充公平的软件展开版 baseline，定量拆分"软件优化收益"与"硬件收益"；
3. 完成第一次 Vivado 综合，获取资源（LUT/FF/DSP/BRAM）与 Fmax；
4. 选定小型 CNN（候选：手工固定权重的极简 CNN / LeNet / 极简 2-conv），
   至少跑通一层卷积调用 CFU，开始整网 cycle 统计（软件整网 cycle、
   CFU 整网 cycle、加速比、卷积层占比、Amdahl 分析）。

方案 B（优化设计）按老师给定优先级推进：
① hazard 修复 + 去 nop → ② 单指令多对数 / 累加型批量 MAC → ③ 2 路 MAC 并行
→ ④ INT8 packed MAC。

**最近完成：**

- [√] 配置 WSL2 环境，跑通 CFU-Proving-Ground 仿真流程
- [√] 设计四操作自定义 MAC 指令集（funct3：MUL/LOAD/READ/MAC），cfu.v RTL 实现
- [√] 指令级仿真对拍全部通过（单乘、含负数点积、连续两段点积）
- [√] 软件 Baseline 出数：dot256 与 conv3x3，-O0/-Os/-O2 三级对照，
      cycle 统计与逐位对拍完成（见第六节）
- [√] 发现并定位上游框架缺陷：custom-0 指令的 load-use 冒险未被停顿逻辑覆盖，
      已通过预加载+展开结构规避（详见 progress/issues.md）
- [√] 完成 18 篇候选文献核验（14 篇核实成功）、13 篇核心筛选、6 篇精读阅读卡，
      并按 GB/T 7714-2015 著者-出版年制整理引用格式汇总
- [√] 仓库初始化完成，以标签 `upstream-base`（commit f3de37a）界定贡献边界
- [√] 完成实验设计文档 docs/03-design/experiment_design.md（四问框架 + 四类实验矩阵）
- [√] 完成 Baseline 与问题分析报告（7 页：问题定义、现有方案、环境、
      Baseline 配置、初始结果、主要问题、下一步计划）

**当前问题：**

- [ ] CFU 指令目前带 3 拍 nop 税，根治需修改 proc.v 的 hazard 逻辑（下一阶段任务 1）
- [ ] 现有 Baseline 中 CFU 版使用预加载+展开结构而纯 C 版未展开，
      加速比混合了软件结构收益与硬件收益，需补软件展开版公平对照（下一阶段任务 2）
- [ ] 方案 B（批量 MAC / 2 路并行 / INT8 packed）尚未设计
- [ ] 尚未完成小型 CNN 端到端推理与整网级 cycle 统计
- [ ] Vivado 综合资源/时序数据未出

**下一步：**

- [ ] 按老师 10-07 反馈顺序执行四项任务（见本节开头）
- [ ] 跑实验前先写预测，实测对照（沿用既定实验纪律）
- [ ] 方案 B 设计定稿前更新实验设计文档至 v2

## 六、主要实验结果

测量方法：pg_perf 计数器夹 10 次取总 cycle、扣空夹开销、除 10 得单次均值；
确定性公式初始化（禁 rand）；CFU 与纯 C 逐位对拍通过后计时。

| Experiment | Result | Status |
| ---------- | ------ | ------ |
| CFU 单周期乘法指令仿真（funct3=000） | 与纯 C 结果逐位一致 | 通过 |
| 四操作 MAC 三组对拍（单乘 / 4维点积含负数 / 连续两段点积） | mul=42 OK，dot4=-16 OK，dot2=13 OK | 通过 |
| dot256 加速比（-O0 / -Os / -O2） | 1.16× / **1.57×** / 1.42×（纯 C 7462 / 2825 / 2570，CFU 6428 / 1798 / 1798 cycle） | 完成 |
| conv3x3（8×8,3×3→6×6）加速比（-O0 / -Os / -O2） | 2.09× / **2.56×** / 2.39×（纯 C 16872 / 5311 / 4944，CFU 8052 / 2068 / 2063 cycle） | 完成 |
| 逐拍归因（dot256） | 1.57× 落在预测区间 1.3–1.6：每迭代省约 4 拍（mul 多拍 FSM 停顿 2~3 拍 + 一条 add），lw 与循环控制两侧相同 | 完成 |
| conv3x3 超预测分析 | 2.56× 超出预测：预加载+展开结构消除了内层循环控制开销，收益 = MAC 指令节省 + 循环展开节省（待补软件展开版对照定量拆分） | 完成，待补公平对照 |
| 上游 custom-0 load-use 冒险缺陷定位 | 探针 T1–T4 复现确认，根因定位于 proc.v 的 `If_load_muldiv_use`；已规避（预加载+展开 + 前置 3 nop），待根治 | 已规避 |
| 去 nop 后重测 dot256 + conv3x3 | — | 待测（下一阶段任务 1） |
| 软件展开版公平 baseline | — | 待测（下一阶段任务 2） |
| Vivado 综合（LUT/FF/DSP/BRAM/Fmax） | — | 待测（下一阶段任务 3） |
| 小型 CNN 整网 cycle（软件 / CFU / 加速比 / 卷积占比 / Amdahl 分析） | — | 待测（下一阶段任务 4） |

## 七、仓库目录说明

本仓库基于开源项目 CFU-Proving-Ground 分叉开发。根目录的 `Makefile`、`cfu.v`、`main.v`、`proc.v`、`top.v`、`app/`、`constr/`、`scripts/` 等均为上游工程原有文件，因构建流程使用相对路径，**保持原位置不动**。

本人毕设材料位于以下新建目录：

| 目录 | 内容 |
|---|---|
| `docs/01-topic/` | 题目确认、任务书要求、技术路线 |
| `docs/02-literature/` | 文献清单、核验报告（含引用格式汇总）、阅读卡 |
| `docs/03-design/` | 系统架构、实验设计（experiment_design.md v1） |
| `experiments/` | 各实验的配置、命令、数据、笔记（baseline / exp01 / exp02 / exp03_hazard_probe） |
| `progress/` | 里程碑、周志、问题记录 |
| `results/` | 正式实验图表与日志 |
| `thesis/` | 论文提纲与草稿（含 Baseline 与问题分析报告） |
| `data/` | 数据说明 |

本人对上游代码的修改集中在 `cfu.v`（自定义 MAC 指令）、`main.c`（测试程序）、`Makefile`、`.gitignore`，可用 `git diff upstream-base..HEAD` 查看全部改动。

## 八、本人主要贡献

### 本人完成的工作

- **自定义 MAC 指令集设计**：基于 RISC-V custom-0 编码空间设计四操作指令（MUL / LOAD / READ / MAC），以 funct3 字段选择操作，软硬件两端约定即指令定义
- **CFU 硬件实现**：在 `cfu.v` 中实现单周期 MAC 数据通路与累加寄存器，全部操作单周期完成（`stall_o` 恒 0）
- **验证程序编写**：在 `main.c` 中以内联汇编（`.insn r 0x0B`）封装 CFU 调用，实现 CFU 与纯 C 的逐位对拍测试
- **构建环境适配**：修改 `Makefile` 适配本地 RISC-V 工具链（含 `OPT ?=` 优化级别参数）；CFU_OP 宏改为字符串化以兼容 -O0/-Os/-O2 全优化级
- **上游缺陷定位**：通过对照实验与探针程序（T1–T4）定位 CFU-Proving-Ground 的 custom-0 load-use 冒险缺陷（proc.v 的 `If_load_muldiv_use` 未将 CFU 纳入消费者侧停顿检测），给出规避方案
- **Baseline 测量方法学**：建立"先预测后实测、先对拍后计时、单变量控制"的实验流程与 pg_perf 计数器测量规范（夹 10 次扣空夹取均值、确定性初始化）
- **文献工作**：候选文献逐条核验（真伪 / 出处 / 年份 / 作者 / DOI），完成 6 篇精读阅读卡，按 GB/T 7714-2015 著者-出版年制整理引用格式

### 第三方项目与工具

- **CFU-Proving-Ground**：[archlab-sciencetokyo / Kise Lab](https://github.com/archlab-sciencetokyo/CFU-Proving-Ground)，作为本课题的基础实验框架，使用其现有 RV32IM 软核、CFU 接口及相关测试环境。具体来源和许可证信息以项目仓库为准。
- **RISC-V 工具链、Verilator、Vivado 等**：作为编译、仿真和 FPGA 综合工具使用，不作为本人原创工作。

## 九、参考项目与第三方代码

- 项目：CFU-Proving-Ground
- URL：https://github.com/archlab-sciencetokyo/CFU-Proving-Ground
- License：MIT License
- 项目来源：archlab-sciencetokyo / Science Tokyo
- 分叉基点：commit f3de37a（仓库标签 `upstream-base`）
- 本项目修改内容：`cfu.v`（实现自定义 MAC 指令）、`main.c`（测试与 Benchmark 程序）、`Makefile`（本地工具链适配）、`.gitignore`；全部改动可用 `git diff upstream-base..HEAD` 查看

## 十、环境与复现

- **OS**：Windows 11 + WSL2 Ubuntu
- **仿真**：Verilator 5（`make run` 运行仿真并输出结果）
- **编译**：RISC-V GCC 工具链（随仓库配置，`make prog` 生成程序；注意：改程序后必须 `make`（prog+build）再 `make run`）
- **FPGA 综合**：Vivado 2026.1（Windows 原生，Basic Tier 许可证）
- **目标板卡**：Digilent Nexys A7-100T（xc7a100tcsg324-1），实板验证为拓展目标
