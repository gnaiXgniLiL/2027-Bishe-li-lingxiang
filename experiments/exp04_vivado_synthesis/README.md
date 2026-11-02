# EXP04：原始 CPU＋CFU 设计的 Vivado 实现与时序验证

## 1. 实验目的

在真实 FPGA 工具链中完成原始 CPU＋CFU 设计的综合、布局布线和比特流生成，记录全系统资源占用，并验证不同目标频率下的时序收敛情况。

## 2. 实验平台

- Vivado：2026.1
- 开发板：Nexys A7
- 器件：xc7a100tcsg324-1
- 顶层模块：main
- 报告阶段：Physopt postRoute
- RTL：两次实验保持一致，仅修改 CLK_FREQ_MHZ

## 3. 实验设计

第一次目标频率为 160 MHz，第二次降低为 80 MHz，第三次设置为85MHz。
三次均执行综合、实现和比特流生成，并保存实现后的资源与时序报告。

最终结论以 postRoute 报告为准。

## 4. 实测结果

| 指标 | 160 MHz | 80 MHz | 85MHz |
|---|---:|---:|---:|
| 时钟周期（ns） | 6.250 | 12.500 | 11.765 |
| Slice LUTs | 1804 | 1746 | 1753 |
| Slice Registers（FF） | 918 | 884 | 890 |
| DSP | 7 | 7 | 7 |
| BRAM Tile | 19 | 19 | 19 |
| WNS（ns） | -5.026 | +0.045 | +0.05 |
| TNS（ns） | -386.248 | 0.000 | 0.000 |
| 建立时间失败端点 | 361 | 0 | 0 |
| WHS（ns） | +0.024 | +0.056 | +0.106 |
| 时序结论 | 未收敛 | 收敛 | 收敛 |

## 5. 预测对照与结论

三次最差路径均通向 CFU 累加寄存器，并包含 DSP 和进位逻辑，
说明 CFU 乘加组合路径是当前时序优化的重要对象。

原始设计已经验证可在 80,85 MHz 下满足当前时序约束，85 MHz 是目前的最高已验证通过频率，但精确 Fmax 尚未确定。

## 6. 当前限制与后续工作

## 7. 原始报告

- reports/utilization_impl_160mhz.rpt
- reports/timing_impl_160mhz.rpt
- reports/utilization_impl_80mhz.rpt
- reports/timing_impl_80mhz.rpt
- reports/utilization_impl_85mhz.rpt
- reports/timing_impl_85mhz.rpt