/**
  ******************************************************************************
  * @file    magic.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Mar 25 09:05:30 2020
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "magic.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"

#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_magic
 
#undef AI_MAGIC_MODEL_SIGNATURE
#define AI_MAGIC_MODEL_SIGNATURE     "6f650d093aab801f256b4934ba6e2543"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.0.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Mar 25 09:05:30 2020"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_MAGIC_N_BATCHES
#define AI_MAGIC_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #1 */
AI_STATIC ai_array dense_5_bias_array;   /* Array #2 */
AI_STATIC ai_array dense_5_weights_array;   /* Array #3 */
AI_STATIC ai_array dense_4_bias_array;   /* Array #4 */
AI_STATIC ai_array dense_4_weights_array;   /* Array #5 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #6 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #7 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #8 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #9 */
AI_STATIC ai_array input_0_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #11 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #12 */
AI_STATIC ai_array dense_4_output_array;   /* Array #13 */
AI_STATIC ai_array nl_4_output_array;   /* Array #14 */
AI_STATIC ai_array dense_5_output_array;   /* Array #15 */
AI_STATIC ai_array nl_6_output_array;   /* Array #16 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor dense_5_bias;   /* Tensor #2 */
AI_STATIC ai_tensor dense_5_weights;   /* Tensor #3 */
AI_STATIC ai_tensor dense_4_bias;   /* Tensor #4 */
AI_STATIC ai_tensor dense_4_weights;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #9 */
AI_STATIC ai_tensor input_0_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_2_output0;   /* Tensor #13 */
AI_STATIC ai_tensor dense_4_output;   /* Tensor #14 */
AI_STATIC ai_tensor nl_4_output;   /* Tensor #15 */
AI_STATIC ai_tensor dense_5_output;   /* Tensor #16 */
AI_STATIC ai_tensor nl_6_output;   /* Tensor #17 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_4_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain nl_4_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_5_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain nl_6_chain;   /* Chain #5 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d_nl_pool conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_dense dense_4_layer; /* Layer #2 */
AI_STATIC ai_layer_nl nl_4_layer; /* Layer #3 */
AI_STATIC ai_layer_dense dense_5_layer; /* Layer #4 */
AI_STATIC ai_layer_nl nl_6_layer; /* Layer #5 */


/**  Array declarations section  **********************************************/
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 48,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_0_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 72,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 4,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 64,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 16,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 3584,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 16,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 512,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 8,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 96,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 384,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_0_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 336,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 224,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_4_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 16,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    nl_4_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 16,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_5_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 4,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    nl_6_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 4,
     AI_STATIC)




/**  Tensor declarations section  *********************************************/
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 1, 3), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_scratch0_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 8, 3, 3), AI_STRIDE_INIT(4, 4, 4, 32, 96),
  1, &conv2d_0_scratch0_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_5_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &dense_5_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_5_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 16, 4, 1, 1), AI_STRIDE_INIT(4, 4, 64, 256, 256),
  1, &dense_5_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_4_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &dense_4_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_4_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 224, 16, 1, 1), AI_STRIDE_INIT(4, 4, 896, 14336, 14336),
  1, &dense_4_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 8, 1, 4, 16), AI_STRIDE_INIT(4, 4, 32, 32, 128),
  1, &conv2d_2_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_0_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 4, 8), AI_STRIDE_INIT(4, 4, 4, 12, 48),
  1, &conv2d_0_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 1, 3, 128), AI_STRIDE_INIT(4, 4, 4, 4, 12),
  1, &input_0_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 8, 1, 42), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_0_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 1, 14), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output0, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &conv2d_2_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_4_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &dense_4_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  nl_4_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &nl_4_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_5_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &dense_5_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  nl_6_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &nl_6_output_array, NULL)


/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&input_0_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_0_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_ENTRY(&conv2d_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 0,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &conv2d_0_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 2, 1), 
  .pool_size = AI_SHAPE_2D_INIT(3, 3), 
  .pool_stride = AI_SHAPE_2D_INIT(3, 3), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&conv2d_0_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_2_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_ENTRY(&conv2d_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &dense_4_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 0, 2, 0), 
  .pool_size = AI_SHAPE_2D_INIT(1, 3), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 3), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 2, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&conv2d_2_output0),
  AI_TENSOR_LIST_ENTRY(&dense_4_output),
  AI_TENSOR_LIST_ENTRY(&dense_4_weights, &dense_4_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_4_layer, 4,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &nl_4_layer, AI_STATIC,
  .tensors = &dense_4_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_4_output),
  AI_TENSOR_LIST_ENTRY(&nl_4_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_4_layer, 4,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_5_layer, AI_STATIC,
  .tensors = &nl_4_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&nl_4_output),
  AI_TENSOR_LIST_ENTRY(&dense_5_output),
  AI_TENSOR_LIST_ENTRY(&dense_5_weights, &dense_5_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_5_layer, 5,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &nl_6_layer, AI_STATIC,
  .tensors = &dense_5_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_5_output),
  AI_TENSOR_LIST_ENTRY(&nl_6_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_6_layer, 6,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &nl_6_layer, AI_STATIC,
  .tensors = &nl_6_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 17200, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1824, 1,
                     NULL),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_MAGIC_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_MAGIC_OUT_NUM, &nl_6_output),
  &conv2d_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool magic_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_2_scratch0_array.data = AI_PTR(activations + 1536);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 1536);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 1536);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 1536);
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    conv2d_0_output_array.data = AI_PTR(activations + 192);
    conv2d_0_output_array.data_start = AI_PTR(activations + 192);
    conv2d_2_output_array.data = AI_PTR(activations + 0);
    conv2d_2_output_array.data_start = AI_PTR(activations + 0);
    dense_4_output_array.data = AI_PTR(activations + 1472);
    dense_4_output_array.data_start = AI_PTR(activations + 1472);
    nl_4_output_array.data = AI_PTR(activations + 1472);
    nl_4_output_array.data_start = AI_PTR(activations + 1472);
    dense_5_output_array.data = AI_PTR(activations + 1456);
    dense_5_output_array.data_start = AI_PTR(activations + 1456);
    nl_6_output_array.data = AI_PTR(NULL);
    nl_6_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool magic_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_5_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_5_bias_array.data = AI_PTR(weights + 17184);
    dense_5_bias_array.data_start = AI_PTR(weights + 17184);
    dense_5_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_5_weights_array.data = AI_PTR(weights + 16928);
    dense_5_weights_array.data_start = AI_PTR(weights + 16928);
    dense_4_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_4_bias_array.data = AI_PTR(weights + 16864);
    dense_4_bias_array.data_start = AI_PTR(weights + 16864);
    dense_4_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_4_weights_array.data = AI_PTR(weights + 2528);
    dense_4_weights_array.data_start = AI_PTR(weights + 2528);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 2464);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 2464);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 416);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 416);
    conv2d_0_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_bias_array.data = AI_PTR(weights + 384);
    conv2d_0_bias_array.data_start = AI_PTR(weights + 384);
    conv2d_0_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_weights_array.data = AI_PTR(weights + 0);
    conv2d_0_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_magic_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_MAGIC_MODEL_NAME,
      .model_signature   = AI_MAGIC_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 69556,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_magic_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_magic_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_magic_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_magic_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= magic_configure_weights(net_ctx, &params->params);
  ok &= magic_configure_activations(net_ctx, &params->activations);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_magic_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_magic_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}

#undef AI_MAGIC_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

