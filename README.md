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

CFU-Proving-Ground 基础环境已搭建完成，已在 WSL Ubuntu 环境下成功运行项目自带仿真流程，确认现有 RV32IM 软核、CFU 接口及测试环境能够正常工作。目前进入“理解现有 CFU 接口与 Verilog/RTL 代码，并准备实现自定义 MAC”的阶段。

**最近完成：**

- [√] 配置 WSL Ubuntu 开发环境
- [√] 获取并配置 archlab-sciencetokyo/CFU-Proving-Ground 项目
- [√] 成功运行项目基础仿真
- [√] 成功运行项目中的随机数字生成/测试界面
- [√] 确认现有 RV32IM 软核及 CFU 接口可以正常工作
- [√] 开始学习 Verilog RTL，已完成 HDLBits 基础组合逻辑、向量、模块例化、`always` / `case` 等内容
- [√] 已具备 Logisim sCPU、寄存器、ALU、控制逻辑等数字系统基础

**当前问题：**

- [ ] 尚未完全理解 CFU 接口各信号及调用流程
- [ ] Verilog 语法和 RTL 编码尚不熟练
- [ ] 尚未系统实现乘法器和 MAC
- [ ] 尚未实现多周期 MAC 的时序控制与握手
- [ ] 尚未建立软件 MAC / 卷积 Baseline
- [ ] 尚未完成自定义 MAC 的 RTL 仿真和正确性验证

**下一步：**

- [ ] 阅读并理解 CFU-Proving-Ground 的 `cfu.v` / CFU 接口及相关调用流程
- [ ] 补充 Verilog 时序逻辑、寄存器、FSM、乘法器等基础
- [ ] 实现并验证基础 MAC
- [ ] 将 MAC 扩展为符合 CFU 接口的多周期自定义功能单元
- [ ] 建立软件 MAC / 卷积 Baseline
- [ ] 完成单 MAC CFU 的 RTL 仿真和正确性验证

## 六、主要实验结果

| Experiment | Result | Status |
| ---------- | ------ | ------ |

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

### 第三方项目与工具

- **CFU-Proving-Ground**：[archlab-sciencetokyo / Kise Lab](https://github.com/archlab-sciencetokyo/CFU-Proving-Ground)，作为本课题的基础实验框架，使用其现有 RV32IM 软核、CFU 接口及相关测试环境。具体来源和许可证信息以项目仓库为准。
- **RISC-V 工具链、Verilator、Vivado 等**：作为编译、仿真和 FPGA 综合工具使用，不作为本人原创工作。

## 九、参考项目与第三方代码

项目： CFU-Proving-Ground
URL： https://github.com/archlab-sciencetokyo/CFU-Proving-Ground
License： MIT License
项目来源： archlab-sciencetokyo / Science Tokyo

## 十、环境与复现

Python / MCU / FPGA / OS / 依赖版本等。