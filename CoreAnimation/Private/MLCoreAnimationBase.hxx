/*
 * Created on Thu Jun 20 02:43:48 CEST 2024
 *
 * Copyright (c) 2024 Zeta Electronics Corporation
 */

#pragma once

#include <Foundation.hxx>

/// DEFINE CORE TYPES ///

typedef float  CAReal;
typedef size_t CASizeT;
typedef bool   CABoolean;

/// DEFINE CORE STRUCTS ///

typedef struct MLCoreAnimationPoint final
{
	CAReal X, Y;
} MLCoreAnimationPoint;

typedef struct MLCoreAnimationRect final
{
	CAReal X1, Y1;
	CAReal X2, Y2;
} MLCoreAnimationRect;

/// DEFINE CORE ALGORITHMS ///

enum
{
    eKineticAlgo,
    eFadeInAlgo,
    eFadeOutAlgo,
    eSmartSmoothAlgo,
};