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

- [ ] **Baseline / 基础系统**
  - [ ] 基于 CFU-Proving-Ground 现有 RV32IM 软核建立可运行的实验环境
  - [ ] 实现纯软件 MAC / 卷积 Baseline
  - [ ] 使用 RISC-V 工具链编译并运行
  - [ ] 完成软件方案的 cycle 数统计
  - [ ] 对比不同编译优化级别（如 `-O0` / `-O2`）

- [ ] **核心方法或关键机制**
  - [ ] 理解并使用现有 CFU 接口
  - [ ] 设计并实现 RISC-V 自定义 MAC 指令对应的 CFU
  - [ ] 完成 MAC 数据通路、累加寄存器及必要的时序控制
  - [ ] 完成 CFU RTL 仿真
  - [ ] 将自定义 MAC 接入至少一个卷积算子
  - [ ] 在小型 CNN 上完成端到端推理

- [ ] **对比实验**
  - [ ] 软件 MAC / 卷积 Baseline
  - [ ] CFU 单 MAC 方案
  - [ ] CFU 优化方案
  - [ ] 对比不同方案的 cycle 数
  - [ ] 分别统计卷积算子级和整网级性能
  - [ ] 计算相对加速比

- [ ] **消融 / 性能测试**
  - [ ] 完成至少一种明确的硬件优化方案
  - [ ] 比较不同设计方案的性能差异
  - [ ] 完成 Vivado 综合
  - [ ] 统计 LUT、FF、DSP、BRAM、Fmax 等指标
  - [ ] 分析硬件资源与计算性能之间的权衡

- [ ] **错误或异常情况分析**
  - [ ] 软件参考结果与 CFU 结果逐位比对
  - [ ] 分析 RTL 仿真中的功能错误及边界情况
  - [ ] 分析软件与硬件结果不一致的原因
  - [ ] 分析不同方案可能存在的性能瓶颈和资源开销

- [ ] **完整毕业论文**
  - [ ] 完成相关研究与技术背景
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

**当前阶段：**

软件 Baseline 构建阶段。硬件侧已超前完成单 MAC 方案的设计与仿真验证，当前任务是补齐纯软件 Baseline 的 cycle 数据，作为后续所有加速比对比的基准。

**最近完成：**

- [√] 配置 WSL2 Ubuntu 开发环境，跑通 CFU-Proving-Ground 原始仿真流程
- [√] Vivado 2026.1 全流程冒烟验证（综合→实现→布线→比特流，0 error，时序收敛）
- [√] 深入理解 CFU 接口与处理器译码通路（proc.v 中 custom-0 指令的译码与执行路径）
- [√] 设计四操作自定义 MAC 指令集（funct3 编码：MUL / LOAD / READ / MAC）
- [√] 完成 cfu.v 四操作 MAC 的 RTL 实现，三组仿真对拍全部通过（单乘、4 维点积含负数、连续两段点积验证装载清场）
- [√] 完成 17 篇候选文献逐条核验，筛出 12 篇核心文献，完成 6 篇精读阅读卡
- [√] 完成仓库统一与初始化，以标签 `upstream-base`（commit f3de37a）界定上游与本人贡献边界

**当前问题：**

- [ ] 软件 Baseline 尚无 cycle 数据（256 维点积 microbenchmark 与 mac_dot / conv3x3 未运行）
- [ ] Makefile 的 `prog` 目标写死 `-Os`，做 -O0 / -O2 对照实验需调整
- [ ] 优化方案（方案 B：多周期 MAC / 单指令多对数 / INT8 packed）尚未设计

**下一步：**

- [ ] 运行 microbenchmark：256 维点积，纯 C 循环 vs CFU 指令，perf 计数器各夹 10 次并扣除空夹开销，输出 cycle 数、加速比并逐位对拍
- [ ] 运行软件 Baseline 正式版：mac_dot(256) + conv3x3（8×8 输入、3×3 核），-O0 / -O2 各一组
- [ ] 撰写 docs/03-design/experiment_design.md（实验设计文档）
- [ ] 撰写 Baseline 与问题分析报告

## 六、主要实验结果

| Experiment | Result | Status |
| ---------- | ------ | ------ |
| CFU 单周期乘法指令仿真（funct3=000） | 与纯 C 结果逐位一致 | 通过 |
| 四操作 MAC 三组对拍（单乘 / 4维点积含负数 / 连续两段点积） | mul=42 OK，dot4=-16 OK，dot2=13 OK | 通过 |
| 软件 Baseline cycle 统计（-O0 / -O2） | — | 待测 |
| CFU 单 MAC vs 软件 Baseline 加速比 | 预测约 1.3–1.6 倍（依据：省 mul 多拍停顿与 add，lw 与循环控制两边相同，受 Amdahl 定律限制） | 待测 |

## 七、仓库目录说明

本仓库基于开源项目 CFU-Proving-Ground 分叉开发。根目录的 `Makefile`、`cfu.v`、`main.v`、`proc.v`、`top.v`、`app/`、`constr/`、`scripts/` 等均为上游工程原有文件，因构建流程使用相对路径，**保持原位置不动**。

本人毕设材料位于以下新建目录：

| 目录 | 内容 |
|---|---|
| `docs/01-topic/` | 题目确认、任务书要求、技术路线 |
| `docs/02-literature/` | 文献清单、核验报告、阅读卡 |
| `docs/03-design/` | 系统架构、实验设计 |
| `experiments/` | 各实验的配置、命令、数据、笔记 |
| `progress/` | 里程碑、周志、问题记录 |
| `results/` | 正式实验图表与日志 |
| `thesis/` | 论文提纲与草稿 |
| `data/` | 数据说明 |

本人对上游代码的修改集中在 `cfu.v`（自定义 MAC 指令）、`main.c`（测试程序）、`Makefile`、`.gitignore`，可用 `git diff upstream-base..HEAD` 查看全部改动。

## 八、本人主要贡献

### 本人完成的工作

- **自定义 MAC 指令集设计**：基于 RISC-V custom-0 编码空间设计四操作指令（MUL / LOAD / READ / MAC），以 funct3 字段选择操作，软硬件两端约定即指令定义
- **CFU 硬件实现**：在 `cfu.v` 中实现单周期 MAC 数据通路与累加寄存器，全部操作单周期完成（`stall_o` 恒 0）
- **验证程序编写**：在 `main.c` 中以内联汇编（`.insn r 0x0B`）封装 CFU 调用，实现 CFU 与纯 C 的逐位对拍测试
- **构建环境适配**：修改 `Makefile` 适配本地 RISC-V 工具链
- **文献工作**：候选文献逐条核验（真伪 / 出处 / 年份 / 作者 / DOI），完成 6 篇精读阅读卡

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
- **编译**：RISC-V GCC 工具链（随仓库配置，`make prog` 生成程序）
- **FPGA 综合**：Vivado 2026.1（Windows 原生，Basic Tier 许可证）
- **目标板卡**：Digilent Nexys A7-100T（xc7a100tcsg324-1），实板验证为拓展目标