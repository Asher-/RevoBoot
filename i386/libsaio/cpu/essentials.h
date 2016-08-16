/*
 * Copyright (c) 2000-2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 *
 * @OSF_COPYRIGHT@
 *
 * Updates:
 *
 *			- New Haswell (ULT) specific MSR's added (Pike, April 2013).
 */

#ifndef __LIBSAIO_CPU_ESSENTIALS_H
#define __LIBSAIO_CPU_ESSENTIALS_H


/* Copied from xnu/osfmk/cpuid.c */
#define bit(n)				(1UL << (n))
#define bitmask32(h, l)		((bit(h) | (bit(h) - 1)) & ~ (bit(l) - 1))
#define bitfield32(x, h, l)	(((x) & bitmask32(h, l)) >> l)


// Added by DHP in 2010.
#define CPU_VENDOR_INTEL	0x756E6547
#define CPU_VENDOR_AMD		0x68747541


/* Copied from xnu/osfmk/cpuid.h */
#define CPU_STRING_UNKNOWN "Unknown CPU Typ"

// Copied from xnu/osfmk/proc_reg.h
#define MSR_IA32_PLATFORM_ID		0x17
#define	MSR_CORE_THREAD_COUNT		0x35

#ifndef MSR_PLATFORM_INFO
	#define MSR_PLATFORM_INFO		0xCE
#endif

#define MSR_PKG_CST_CONFIG_CONTROL	0xE2	// MSR_PKG_CST_CONFIG_CONTROL
#define MSR_PMG_IO_CAPTURE_BASE		0xE4
#define IA32_MPERF					0xE7
#define IA32_APERF					0xE8

#define	MSR_IA32_PERF_STATUS		0x0198	// MSR_IA32_PERF_STS in XNU
#define	MSR_IA32_PERF_CONTROL		0x0199	// IA32_PERF_CTL

#ifndef MSR_FLEX_RATIO
	#define MSR_FLEX_RATIO			0x0194
#endif

#define IA32_CLOCK_MODULATION		0x019A
#define IA32_THERM_STATUS			0x019C

#define IA32_MISC_ENABLES			0x01A0
#define MSR_TEMPERATURE_TARGET		0x01A2
#define MSR_MISC_PWR_MGMT			0x01AA
#define	MSR_TURBO_RATIO_LIMIT		0x01AD
#define	MSR_TURBO_RATIO_LIMIT_1		0x01AE
#define	MSR_TURBO_RATIO_LIMIT_2		0x01AF

#define IA32_ENERGY_PERF_BIAS		0x01B0
#define IA32_PLATFORM_DCA_CAP		0x01F8
#define MSR_POWER_CTL				0x01FC

#define MSR_PKGC3_IRTL				0x60A
#define MSR_PKGC6_IRTL				0x60B
#define MSR_PKGC7_IRTL				0x60C

#define MSR_PKG_C2_RESIDENCY		0x60D
#define MSR_PKG_C3_RESIDENCY		0x3F8
#define MSR_PKG_C6_RESIDENCY		0x3F9
#define MSR_PKG_C7_RESIDENCY		0x3FA

#define MSR_CORE_C3_RESIDENCY		0x3FC
#define MSR_CORE_C6_RESIDENCY		0x3FD
#define MSR_CORE_C7_RESIDENCY		0x3FE

#define MSR_PP0_CURRENT_CONFIG		0x601
#define MSR_PP1_CURRENT_CONFIG		0x602

// Sandy Bridge & JakeTown specific 'Running Average Power Limit' MSR's.
#define MSR_RAPL_POWER_UNIT			0x606

#define MSR_PKG_POWER_LIMIT			0x610
#define MSR_PKG_ENERGY_STATUS		0x611
#define MSR_PKG_PERF_STATUS			0x613
#define MSR_PKG_POWER_INFO			0x614

// JakeTown only Memory MSR's.
#define MSR_DRAM_POWER_LIMIT		0x618
#define MSR_DRAM_ENERGY_STATUS		0x619
#define MSR_DRAM_PERF_STATUS		0x61B
#define MSR_DRAM_POWER_INFO			0x61C

// Haswell-ULT Package residency
#define MSR_PKG_C8_RESIDENCY		0x630
#define MSR_PKG_C9_RESIDENCY		0x631
#define MSR_PKG_C10_RESIDENCY		0x632

// Haswell-ULT C state latency control.
#define MSR_PKG_C8_LATENCY			0x633
#define MSR_PKG_C9_LATENCY			0x634
#define MSR_PKG_C10_LATENCY			0x635

// Haswell-ULT VR configurations.
#define VR_MISC_CONFIG2				0x636

// Haswell-ULT Alternate BCLK in deep Package C states.
#define MSR_COUNTER_24_MHZ			0x637

// Sandy Bridge IA (Core) domain MSR's.
#define MSR_PP0_POWER_LIMIT			0x638
#define MSR_PP0_ENERGY_STATUS		0x639
#define MSR_PP0_POLICY				0x63A
#define MSR_PP0_PERF_STATUS			0x63B

// Sandy Bridge Uncore (IGPU) domain MSR's (Not on JakeTown).
#define MSR_PP1_POWER_LIMIT			0x640
#define MSR_PP1_ENERGY_STATUS		0x641
#define MSR_PP1_POLICY				0x642

// Ivy Bridge Specific MSR's
#define MSR_CONFIG_TDP_NOMINAL		0x648
#define MSR_CONFIG_TDP_LEVEL1		0x649
#define MSR_CONFIG_TDP_LEVEL2		0x64A
#define MSR_CONFIG_TDP_CONTROL		0x64B
#define MSR_TURBO_ACTIVATION_RATIO	0x64C

// CPUID leaf index values (pointing to the right spot in CPUID/LEAF array).

#define LEAF_0				0		// Basic CPUID Information
#define LEAF_1				1
#define LEAF_2				2
#define LEAF_4				3		// Deterministic Cache Parameters Leaf
#define LEAF_5				4		// MONITOR/MWAIT Leaf
#define LEAF_6				5		// Thermal and Power Management Leaf
#define LEAF_B				6		// Extended Topology Enumeration Leaf
#define LEAF_15				7		// Time Stamp Counter/Core Crystal Clock Information-leaf
#define LEAF_16				8		// Processor Frequency Information Leaf
#define LEAF_80				9		// Extended Function CPUID Information
#define LEAF_81				10

#define MAX_CPUID_LEAVES	11		// DHP: Formerly known as MAX_CPUID

/* Copied from: xnu/osfmk/i386/cpuid.h */
#define CPU_MODEL_YONAH  			0x0E
#define CPU_MODEL_MEROM				0x0F
#define CPU_MODEL_PENRYN			0x17
#define CPU_MODEL_NEHALEM			0x1A
#define CPU_MODEL_ATOM				0x1C
#define CPU_MODEL_FIELDS			0x1E	// Lynnfield, Clarksfield, Jasper (LGA 1156)
#define CPU_MODEL_DALES				0x1F	// Havendale, Auburndale (LGA 1156)
#define CPU_MODEL_DALES_32NM		0x25	// Clarkdale, Arrandale
#define CPU_MODEL_SB_CORE			0x2A	// Sandy Bridge Core Processors (LGA 1155)
#define CPU_MODEL_WESTMERE			0x2C	// Gulftown, Westmere-EP, Westmere-WS
#define CPU_MODEL_SB_JAKETOWN		0x2D	// Sandy Bridge-EP, Sandy Bridge Xeon Processors (LGA 2011)
#define CPU_MODEL_NEHALEM_EX		0x2E
#define CPU_MODEL_WESTMERE_EX		0x2F
#define CPU_MODEL_IB_CORE			0x3A	// Ivy Bridge Core Processors (LGA 1155)
#define CPU_MODEL_IB_CORE_EX		0x3B	// Ivy Bridge Core Processors (LGA 2011)
#define CPU_MODEL_IB_CORE_XEON		0x3E

#define CPU_MODEL_HASWELL			0x3C
#define CPU_MODEL_HASWELL_E			0x3F
#define CPU_MODEL_HASWELL_ULT		0x45
#define CPU_MODEL_CRYSTALWELL		0x46

#define CPU_MODEL_BROADWELL			0x3D
#define CPU_MODEL_BROADWELL_ULX		0x3D
#define CPU_MODEL_BROADWELL_ULT		0x3D
#define CPU_MODEL_BROADWELL_H		0x47
#define CPU_MODEL_BRYSTALWELL		0x4C
#define CPU_MODEL_BROADWELL_E		0x4F
#define CPU_MODEL_BROADWELL_DE		0x56

#define CPU_MODEL_SKYLAKE			0x4E
#define CPU_MODEL_SKYLAKE_ULT		0x4E
#define CPU_MODEL_SKYLAKE_ULX		0x4E
#define CPU_MODEL_SKYLAKE_X			0x55
#define CPU_MODEL_SKYLAKE_DT		0x5E

#define CPU_MODEL_KABYLAKE			0x8E
#define CPU_MODEL_KABYLAKE_DT		0x9E

#define DALES_BRIDGE	1
#define SANDY_BRIDGE	2
#define IVY_BRIDGE		4
#define HASWELL			8
#define BROADWELL		16
#define SKYLAKE			32
#define KABYLAKE		64

#endif /* !__LIBSAIO_CPU_ESSENTIALS_H */
