/*==========================================================
Copyright (c) 2023 UDS
Unpublished - All rights reserved
===========================================================
File description:
dll Global for SweptCalc.lib
===========================================================
Date            Name                 Description of Change
2023-09-18      WSF                  First Edition
==========================================================*/
#pragma once
#ifdef EXPORTS_SWEPTCALC_DEF
#define EXPORTS_SWEPTCALC __declspec(dllexport)
#else
#define EXPORTS_SWEPTCALC __declspec(dllimport)
#endif

