# EXP01：CFU-Proving-Ground 原始环境与 Verilator 仿真验证

## 1. 实验目的

1. 完整运行 CFU-Proving-Ground 原始项目；
2. 验证 WSL Ubuntu 开发环境配置正确；
3. 验证项目自带 Verilator 仿真流程能够正常运行；
4. 初步确认项目中的 RISC-V 软核、CFU 接口及测试程序能够正常工作。

## 2. 实验环境

- OS：WSL2 Ubuntu 24.04.3
- Project：CFU-Proving-Ground
- Simulator：Verilator

## 3. 实验步骤

### 3.1 获取项目

```bash
cfu
```

### 3.2 编译与运行
```
make
```
结果：编译正确

```
make drun
```
结果：运行正确


### 4. 实验结论

CFU-Proving-Ground 原始环境已成功配置，并完成项目自带 Verilator 仿真流程。当前环境可以正常运行 RISC-V 软件程序及项目自带测试，为后续分析 CFU 接口以及实现自定义 MAC 加速单元提供基础。























