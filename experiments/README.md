# experiments/

本目录记录全部实验。每个实验一个子目录，内含 README.md（实验记录卡：
目的 / 对照 / 配置 / 数据 / 命令 / 结果 / 结论 / 问题）、配置与原始数据。

## 实验总览

| 目录 | 内容 | 结果 | 状态 |
|---|---|---|---|
| `baseline/` | 软件 Baseline 与 CFU 对照的归档数据（metrics.csv / config / command / notes） | dot256 1.57x、conv3x3 2.56x（-Os） | ✅ 完成 |
| `exp01/` | EXP-001：dot256 microbenchmark，CFU vs 纯软件 | 1.16 / 1.57 / 1.42（-O0/-Os/-O2） | ✅ 完成 |
| `exp02/` | EXP-002：conv3x3（8x8, 3x3），CFU 预加载+展开版 | 2.09 / 2.56 / 2.39（-O0/-Os/-O2） | ✅ 完成 |
| `exp03_hazard_probe/` | custom-0 load-use 冒险定位探针（T1–T4） | 确认缺陷，隔 1 条指令即正确 | ✅ 完成（归档） |

## 规范

- 新实验开新目录，编号递增（exp04_方案B_xxx ...），目录名可带简短主题
- 每个实验的 README.md 按统一模板填写（Purpose / Compared with /
  Configuration / Dataset / Random seed / Command / Result / Conclusion / Problems）
- 数据须确定性可复现：禁止 rand，初始化公式写入 Configuration
- 原始产物留在各实验目录；写入报告/论文的正式图表另存 `results/`
- 所有实验发现的问题登记到 `progress/issues.md`