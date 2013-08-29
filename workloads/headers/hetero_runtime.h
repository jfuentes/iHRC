//===-- HeteroCPUTransform.cpp - Generate CPU/IA code  -------------------===//
//
// Copyright (c) 2013 Intel Corporation. All rights reserved.
//                     The iHRC Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE-iHRC.TXT for details.
//
//===----------------------------------------------------------------------===

#ifndef HETERO_RUNTIME_H
#define HETERO_RUNTIME_H

typedef struct gpu_program_s {
  const char* /*const*/ ir;  // ghal code generated by static compiler
  size_t irSize; // size of ir. can be 0 if ir null-terminated
  void* volatile binary; // Gen program binary generated by JIT compiler
  
  /* for opencl code generation -- in future put this in a new struct? */
  const char* cl_ir;  /* OpenCL kernel generated by opencl backend */
  size_t cl_ir_size;
  void* volatile cl_binary; /* Gen binary for the opencl JIT compiler */

} gpu_program_t;

typedef struct gpu_function_s {
  gpu_program_t *const program;
  const char* /*const*/ name; // function name to lookup
  void* volatile binary;  // Gen function binary generated by JIT compiler
  //int flag;  /* Added by Deepak for delaying init_ocl for graphics display; this should be either in gpu_program_t or be handled in another way */
  /* For OpenCL code generation -- in future put this in in a new struct?*/
  void* volatile cl_binary;  // Gen function binary generated by JIT compiler
  //for reduction
  unsigned int reduction_object_size;
  const char* gpu_reduce_name;
  void* volatile gpu_reduce_binary;

} gpu_function_t;

#endif /* HETERO_RUNTIME_H */