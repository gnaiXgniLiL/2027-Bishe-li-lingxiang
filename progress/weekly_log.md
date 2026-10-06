# 周志

## 2026-10-06 周

**本周完成：**
- 软件 Baseline 全部出数：dot256 加速比 1.16/1.57/1.42（-O0/-Os/-O2），
  conv3x3 加速比 2.09/2.56/2.39，正确性逐位对拍全部通过
- 预测-实测对照：点积 1.57 落在预测区间 1.3-1.6，逐拍归因符合 Amdahl 分析；
  卷积 2.56 超出预测（未预见到展开消除内层循环开销的收益）
- 发现并定位上游框架缺陷：custom-0 指令 load-use 冒险（详见 issues.md #1）
- 仓库统一完成（WSL 正主 + upstream-base 标签界定贡献边界），README 按模板补齐
- 修复 -O0 下内联汇编 "impossible constraint" 编译错误（CFU_OP 改为字符串化宏）

**下周计划：**
- 实验设计文档 experiment_design.md
- Baseline 与问题分析报告
- 方案 B 设计讨论