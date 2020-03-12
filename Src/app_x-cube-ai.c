
#ifdef __cplusplus
 extern "C" {
#endif
/**
  ******************************************************************************
  * @file           : app_x-cube-ai.c
  * @brief          : AI program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V.
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "app_x-cube-ai.h"
#include "main.h"
//#include "constants_ai.h"
#include "ai_datatypes_defines.h"

/* USER CODE BEGIN includes */
/* USER CODE END includes */
/* USER CODE BEGIN initandrun */
#include <stdlib.h>
/*
 const ai_float ring_data[] = {
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    -665.0, 228.0,  827.0,  -680.0, 339.0,  716.0,
     -680.0, 564.0,  812.0,  -679.0, 552.0,  818.0,  -665.0, 528.0,  751.0,
     -658.0, 432.0,  618.0,  -655.0, 445.0,  592.0,  -667.0, 484.0,  556.0,
     -684.0, 590.0,  510.0,  -674.0, 672.0,  475.0,  -660.0, 786.0,  390.0,
     -562.0, 1124.0, 128.0,  -526.0, 1140.0, 111.0,  -486.0, 1044.0, 33.0,
     -416.0, 652.0,  -134.0, -390.0, 534.0,  -143.0, -365.0, 381.0,  -117.0,
     -314.0, 60.0,   94.0,   -322.0, 7.0,    190.0,  -338.0, -95.0,  342.0,
     -360.0, -106.0, 842.0,  -351.0, -41.0,  965.0,  -352.0, 12.0,   960.0,
     -366.0, 42.0,   1124.0, -322.0, 56.0,   1178.0, -312.0, 15.0,   1338.0,
     -254.0, 10.0,   1532.0, -241.0, 5.0,    1590.0, -227.0, 60.0,   1565.0,
     -204.0, 282.0,  1560.0, -180.0, 262.0,  1524.0, -138.0, 385.0,  1522.0,
     -84.0,  596.0,  1626.0, -55.0,  639.0,  1604.0, -19.0,  771.0,  1511.0,
     16.0,   932.0,  1132.0, 15.0,   924.0,  1013.0, 1.0,    849.0,  812.0,
     -88.0,  628.0,  500.0,  -114.0, 609.0,  463.0,  -155.0, 559.0,  382.0,
     -234.0, 420.0,  278.0,  -254.0, 390.0,  272.0,  -327.0, 200.0,  336.0,
     -558.0, -556.0, 630.0,  -640.0, -607.0, 740.0,  -706.0, -430.0, 868.0,
     -778.0, 42.0,   1042.0, -763.0, 84.0,   973.0,  -735.0, 185.0,  931.0,
     -682.0, 252.0,  766.0,  -673.0, 230.0,  757.0,  -671.0, 218.0,  757.0,
     -656.0, 222.0,  714.0,  -659.0, 238.0,  746.0,  -640.0, 276.0,  731.0,
     -634.0, 214.0,  754.0,  -637.0, 207.0,  735.0,  -637.0, 194.0,  742.0,
     -634.0, 248.0,  716.0,  -631.0, 265.0,  697.0,  -628.0, 252.0,  797.0,
     -592.0, 204.0,  816.0,  -618.0, 218.0,  812.0,  -633.0, 231.0,  828.0,
     -640.0, 222.0,  736.0,  -634.0, 221.0,  787.0,
 };

 const ai_float slope_data[] = {
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     0.0,    0.0,    0.0,    -766.0, 132.0,  709.0,  -751.0, 249.0,  659.0,
     -714.0, 314.0,  630.0,  -709.0, 244.0,  623.0,  -707.0, 230.0,  659.0,
     -704.0, 202.0,  748.0,  -714.0, 219.0,  728.0,  -722.0, 239.0,  710.0,
     -744.0, 116.0,  612.0,  -753.0, -49.0,  570.0,  -748.0, -279.0, 527.0,
     -668.0, -664.0, 592.0,  -601.0, -635.0, 609.0,  -509.0, -559.0, 606.0,
     -286.0, -162.0, 536.0,  -255.0, -144.0, 495.0,  -209.0, -85.0,  495.0,
     6.0,    416.0,  698.0,  -33.0,  304.0,  1117.0, -82.0,  405.0,  1480.0,
     -198.0, 1008.0, 1908.0, -229.0, 990.0,  1743.0, -234.0, 934.0,  1453.0,
     -126.0, 838.0,  896.0,  -78.0,  792.0,  911.0,  -27.0,  741.0,  918.0,
     114.0,  734.0,  960.0,  135.0,  613.0,  959.0,  152.0,  426.0,  1015.0,
     106.0,  -116.0, 1110.0, 63.0,   -314.0, 1129.0, -12.0,  -486.0, 1179.0,
     -118.0, -656.0, 1510.0, -116.0, -558.0, 1553.0, -126.0, -361.0, 1367.0,
     -222.0, -76.0,  922.0,  -210.0, -26.0,  971.0,  -194.0, 50.0,   1053.0,
     -178.0, 72.0,   1082.0, -169.0, 100.0,  1073.0, -162.0, 133.0,  1050.0,
     -156.0, 226.0,  976.0,  -154.0, 323.0,  886.0,  -130.0, 240.0,  1154.0,
     -116.0, 124.0,  916.0,  -132.0, 124.0,  937.0,  -153.0, 115.0,  981.0,
     -184.0, 94.0,   962.0,  -177.0, 85.0,   1017.0, -173.0, 92.0,   1027.0,
     -168.0, 158.0,  1110.0, -181.0, 101.0,  1030.0, -180.0, 139.0,  1054.0,
     -152.0, 10.0,   1044.0, -169.0, 74.0,   1007.0,
 };

 const ai_float o_data[] = {
		 0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
		      0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
 -234.9,443.6,1676.7,
 -274.0,502.3,1644.0,
 -267.5,456.7,1631.0,
 -254.4,437.1,1702.8,
 -234.9,456.7,1631.0,
 -254.4,476.2,1670.1,
 -267.5,437.1,1650.6,
 -254.4,417.5,1676.7,
 -254.4,417.5,1663.6,
 -228.3,502.3,1611.4,
 -234.9,482.8,1611.4,
 -293.6,391.4,1650.6,
 -254.4,450.2,1526.6,
 -274.0,404.5,1598.4,
 -306.6,332.7,1598.4,
 -280.5,345.8,1552.7,
 -378.4,306.6,1617.9,
 -424.1,424.1,1559.2,
 -456.7,476.2,1663.6,
 -521.9,339.2,1663.6,
 -541.5,502.3,1637.5,
 -580.6,463.2,1526.6,
 -619.8,352.3,1624.5,
 -632.8,645.9,1572.3,
 -658.9,685.0,1376.6,
 -652.4,750.3,1513.6,
 -678.5,769.8,1441.8,
 -711.1,789.4,1520.1,
 -652.4,815.5,1533.1,
 -685.0,848.1,1611.4,
 -750.3,750.3,1461.4,
 -639.3,998.2,1676.7,
 -743.7,861.2,1559.2,
 -554.5,932.9,1291.7,
 -574.1,913.4,1585.3,
 -450.2,972.1,1324.4,
 -437.1,874.2,1507.0,
 -424.1,809.0,1376.6,
 -319.7,1083.0,1572.3,
 -300.1,939.4,1337.4,
 -208.8,893.8,1422.2,
 -150.1,932.9,1350.5,
 -19.6,939.4,1370.0,
 -84.8,939.4,1343.9,
 32.6,1128.6,1357.0,
 65.2,1011.2,1304.8,
 110.9,991.6,1376.6,
 156.6,1180.8,1402.7,
 195.7,1180.8,1337.4,
 221.8,939.4,1317.8,
 293.6,1030.8,1291.7,
 352.3,1037.3,1148.2,
 417.5,1024.3,1154.7,
 476.2,1024.3,1109.1,
 515.4,965.5,1220.0,
 515.4,932.9,1213.5,
 600.2,1083.0,1206.9,
 606.7,1011.2,1056.9,
 639.3,978.6,1135.2,
 678.5,880.7,1174.3,
 613.3,750.3,1233.0,
 698.1,743.7,1180.8,
 593.7,567.6,1304.8,
 724.2,561.1,1311.3,
 756.8,528.4,1122.1,
 639.3,176.1,1063.4,
 698.1,247.9,1167.8,
 672.0,417.5,1330.9,
 711.1,450.2,1422.2,
 567.6,339.2,1533.1,
 411.0,345.8,1670.1,
 456.7,424.1,1728.8,
 280.5,208.8,1644.0,
 339.2,476.2,1794.1,
 84.8,137.0,1663.6,
 182.7,176.1,1741.9,
 -97.9,384.9,1833.2,
 -58.7,411.0,1213.5,
 -117.4,541.5,2224.7,
 -221.8,319.7,1807.1,
 -182.7,365.3,1826.7,
 -228.3,280.5,1683.2,
 -391.4,261.0,1859.3,
 -424.1,476.2,1689.7,
 -274.0,535.0,1833.2,
 -411.0,208.8,1715.8,
 -287.1,437.1,1702.8,
 -430.6,293.6,1650.6,
 -398.0,300.1,1709.3,
 -424.1,274.0,1794.1,
 -306.6,482.8,1696.2,
 -456.7,352.3,1787.6,
 -280.5,450.2,1676.7,
 -261.0,502.3,1722.3,
 -306.6,202.2,1631.0,
 -280.5,254.4,1754.9,
 -241.4,306.6,1781.0,
 -215.3,130.5,1611.4,
 -221.8,261.0,1689.7,
 };
 */
/* Global handle to reference the instance of the NN */
static ai_handle magic = AI_HANDLE_NULL;
static ai_buffer ai_input[AI_MAGIC_IN_NUM] = AI_MAGIC_IN ;
static ai_buffer ai_output[AI_MAGIC_OUT_NUM] = AI_MAGIC_OUT ;

/*
 * Init function to create and initialize a NN.
 */
int aiInit(const ai_u8* activations)
{
    ai_error err;

    /* 1 - Specific AI data structure to provide the references of the
     * activation/working memory chunk and the weights/bias parameters */
    const ai_network_params params = {
            AI_MAGIC_DATA_WEIGHTS(ai_magic_data_weights_get()),
            AI_MAGIC_DATA_ACTIVATIONS(activations)
    };

    /* 2 - Create an instance of the NN */
    err = ai_magic_create(&magic, AI_MAGIC_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE) {
	    return -1;
    }

    /* 3 - Initialize the NN - Ready to be used */
    if (!ai_magic_init(magic, &params)) {
        err = ai_magic_get_error(magic);
        ai_magic_destroy(magic);
        magic = AI_HANDLE_NULL;
	    return -2;
    }

    return 0;
}

/*
 * Run function to execute an inference.
 */
int aiRun(const void *in_data, void *out_data)
{
    ai_i32 nbatch;
    ai_error err;

    /* Parameters checking */
    if (!in_data || !out_data || !magic)
        return -1;

    /* Initialize input/output buffer handlers */
    ai_input[0].n_batches = 1;
    ai_input[0].data = AI_HANDLE_PTR(in_data);
    ai_output[0].n_batches = 1;
    ai_output[0].data = AI_HANDLE_PTR(out_data);

    /* 2 - Perform the inference */
    nbatch = ai_magic_run(magic, &ai_input[0], &ai_output[0]);
    if (nbatch != 1) {
        err = ai_magic_get_error(magic);
        // ...
        return err.code;
    }

    return 0;
}
/* USER CODE END initandrun */

/*************************************************************************
  *
  */
void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 0 */
    /* Activation/working buffer is allocated as a static memory chunk
     * (bss section) */
    AI_ALIGNED(4)
    static ai_u8 activations[AI_MAGIC_DATA_ACTIVATIONS_SIZE];

    aiInit(activations);
    /* USER CODE END 0 */
}



void MX_X_CUBE_AI_Process_f(float *acc_data, float *out_data)
{
    aiRun((ai_float*)acc_data, (ai_float*)out_data);
}
#ifdef __cplusplus
}
#endif
