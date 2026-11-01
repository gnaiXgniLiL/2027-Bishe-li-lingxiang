# experiments/

本目录记录全部实验。每个实验一个子目录，内含 README.md（实验记录卡：
目的 / 对照 / 配置 / 数据 / 命令 / 结果 / 结论 / 问题）、配置与原始数据。

## 实验总览

| 目录 | 内容 | 结果 | 状态 |
|---|---|---|---|
| `baseline/` | 软件 Baseline 与 CFU 对照的历史归档数据（metrics.csv / config / command / notes） | 历史结果：dot256 1.57×、conv3x3 2.56×（-Os）；详细口径见 metrics.csv 和 notes.md | 完成 |
| `exp01/` | EXP01：dot256 microbenchmark，CFU 与纯软件对照 | 总加速比为 1.16 / 1.57 / 1.42（-O0/-Os/-O2） | 完成 |
| `exp02_hazard/` | EXP02：conv3x3 异常定位、CFU_OP 宏修复及 nop 开销复测 | 根因为宏内变量 r 遮蔽外层循环变量，并非上游 load-use 硬件冒险；proc.v 无需修改；历史 nop 税为 756 cycle | 完成，结论已修正 |
| `exp03_c_unrolled/` | EXP03：C-naive、C-unrolled 与 CFU 三方公平对照 | 软件优化收益 X＝2.014～2.647，硬件净收益 Y＝1.148～1.824，总加速比为 2.312～4.046 | 完成 |
| `exp04_vivado_synthesis/` | EXP04：原始 CPU＋CFU 设计的 Vivado 资源与时序实验 | 160 MHz 未收敛，WNS＝−5.026 ns；80 MHz 收敛，WNS＝+0.045 ns；当前仅验证 80 MHz 可行 | 首轮完成，Fmax 待测 |

## 规范

- 新实验开新目录，编号递增，目录名可带简短主题，例如 `exp05_主题`
- 每个实验的 README.md 按统一模板填写（Purpose / Compared with /
  Configuration / Dataset / Random seed / Command / Result / Conclusion / Problems）
- 数据须确定性可复现：禁止 rand，初始化公式写入 Configuration
- 实验前预测应单独保存，实验结束后另写实测与预测对照，不事后修改预测
- 原始产物留在各实验目录；写入报告或论文的正式图表另存 `results/`
- 所有实验发现的问题登记到 `progress/issues.md`
- 修改软件程序、编译选项或 RTL 后，应重新构建并验证，避免混用旧生成物