#ifndef __BSXLIBRARYCONSTANTS_H__
#define __BSXLIBRARYCONSTANTS_H__
/*!
 * @section LICENCE
 *
 * (C) Copyright 2011~2014 Bosch Sensortec GmbH All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * @file      bsxlibraryconstants.h
 * @date      2013/02/12 created
 *
 * @brief
 * This file provides constants definition
 *
 * @detail
 * bsxlibraryconstants - file provides constants definition used by library
 *
 */

/************************************************************************************************************/
/*												INCLUDES													*/
/************************************************************************************************************/

#include "BsxLibraryDataTypes.h"

/************************************************************************************************************/
/*											CONSTANT DEFINITIONS										        */
/************************************************************************************************************/


/** \def gravity on earth = 9.80665 m/s2 */
#define BSX_GRAVITY                                             (9.80665f)

/**\ def conversion factors */
#define BSX_CONVFACTOR_RES16BIT_UNITS2LSB       (32767.0f)
#define BSX_CONVFACTOR_RES16BIT_LSB2UNITS       (3.0519e-005f)                          /**< 1/32767 */
#define BSX_CONVFACTOR_RES15BIT_UNITS2LSB       (16384.0f)
#define BSX_CONVFACTOR_INV_RES15BIT_UNITS2LSB (6.10351563e-005f)                        /*1/BSX_CONVFACTOR_RES15BIT_UNITS2LSB*/
#define BSX_CONVFACTOR_RES15BIT_LSB2UNITS       (6.1035e-005f)                          /**< calculated as 1/16384 */
#define PI_OVER_TWO                                             (1.570796326794897f)    /*<pi/2*/
#define PI_TIMES_TWO                                            (6.283185307179586f)    /**< 2*pi*/
#define SQRT_TWO_OVER_TWO                                       (0.7071067811865476f)   /*0.5*sqrt(2)*/

#define UNIT_SCALING_ACC_INTERNAL2MPS2          (0.00980665f)                           /**< milli gravity -> metre per second squared 0.0098055  */
#define UNIT_SCALING_ACC_MPS22INTERNAL          (1.019835806435164e+02f)
#define UNIT_SCALING_ACC_INTERNAL2G                     (1e-3f)                         /*internal unit [mg] to [g]*/
#define UNIT_SCALING_ACC_G2INTERNAL         (1000U)                                     /*[g] to internal unit [mg]*/
#define UNIT_SCALING_GYRO_INTERNAL2DEGPS        (6.1e-2f)                               //(0.06103515625f) /* internal unit [0.061 deg/s] to [deg/s]; note: 2000/2^15 = 0.061 ;1/BSX_CONVFACTOR_DPS2LSB */
#define UNIT_SCALING_GYRO_DEGPS2INTERNAL        (16.384f)                               /*[deg/s] to internal unit [0.061 deg/s]; note: 2^15/2000 = 16.384*/
#define UNIT_SCALING_GYRO_INTERNAL2RADPS        (0.001065264436031695f)                 //(0.0011f)			/*internal unit [0.0011 rad/s] to [deg/s]; note: 2000/2^15*pi/180 = 0.0011*/
#define UNIT_SCALING_GYRO_RADPS2INTERNAL        (938.7341f)                             /**< calculated as BSX_CONVFACTOR_DPS2LSB*180/pi */
#define UNIT_SCALING_MAG_INTERNAL2UTESLA        (0.1f)                                  /*internal unit [0.1 uT] to [uT]*/
#define UNIT_SCALING_MAG_UTESLA2INTERNAL        (10U)                                   /*[uT] to internal unit [0.1 uT]*/
/** \def Supported Data Rate */
#define BSX_DATARATE_1HZ                                (0U)
#define BSX_DATARATE_5HZ                                (1U)
#define BSX_DATARATE_10HZ                               (2U)
#define BSX_DATARATE_20HZ                               (3U)
#define BSX_DATARATE_25HZ                               (4U)
#define BSX_DATARATE_40HZ                                       (5U)
#define BSX_DATARATE_50HZ                               (6U)
#define BSX_DATARATE_100HZ                              (7U)
#define BSX_DATARATE_125HZ                                      (8U)
#define BSX_DATARATE_200HZ                              (9U)
#define BSX_DATARATE_400HZ                                      (10U)
#define DATARATE_INVALIDUPPER                           (11U)  /*Upper boundary on allowed values*/

/** \def operational modes */
#define BSX_OPMODE_SLEEP                                (0U)
#define BSX_OPMODE_REGULAR                              (1U)
#define BSX_OPMODE_FIFO                                         (2U)

/** \def Geomagnetic rotation  modes */
#define BSX_NDOFGRV_SLEEP                               (0U)
#define BSX_NDOFGRV_ACTIVE                              (1U)

/** \def filter modes  (0 = bypass; 1 = forward; 2 = backward;) */
#define BSX_FILTERMODE_BYPASS                           (0U)
#define BSX_FILTERMODE_FORWARD                          (1U)
#define BSX_FILTERMODE_BACKWARD                         (2U)

/** \def calibration modes */
//#define BSX_CALIB_SLEEP                                       (0U)
//#define BSX_CALIB_MONITORING                                  (1U)
//#define BSX_CALIB_MODEOFFSETACTIVE                    (2U)

/** \def measurement range of the accelerometer */
#define BSX_ACCRANGE_2G                     (0U)
#define BSX_ACCRANGE_4G                     (1U)
#define BSX_ACCRANGE_8G                     (2U)
#define BSX_ACCRANGE_16G                    (3U)

#define BSX_GYRORANGE_2048DPS                           (0U)    /** Measurement Range 2048 Degrees/sec */
#define BSX_GYRORANGE_2000DPS                           (1U)    /** Measurement Range 2000 Degrees/sec */
#define BSX_GYRORANGE_1000DPS                           (2U)    /** Measurement Range 1000 Degrees/sec */
#define BSX_GYRORANGE_500DPS                            (3U)    /** Measurement Range 500 Degrees/sec */
#define BSX_GYRORANGE_250DPS                            (4U)    /** Measurement Range 250 Degrees/sec */
#define BSX_GYRORANGE_MAX                                       (4U)

/** \def Sensor Accuracy Information */
#define BSX_SENSOR_STATUS_UNRELIABLE            (0U)
#define BSX_SENSOR_STATUS_ACCURACY_LOW          (1U)
#define BSX_SENSOR_STATUS_ACCURACY_MEDIUM       (2U)
#define BSX_SENSOR_STATUS_ACCURACY_HIGH         (3U)

/** \def Constants representing a sensor */
#define BSX_TYPE_ACCELEROMETER                          (1)
#define BSX_TYPE_AMBIENT_TEMPERATURE            (13)
#define BSX_TYPE_GRAVITY                                        (9)
#define BSX_TYPE_GYROSCOPE                                      (4)
#define BSX_TYPE_LIGHT                                          (5)
#define BSX_TYPE_LINEAR_ACCELERATION            (10)
#define BSX_TYPE_MAGNETIC_FIELD                         (2)
#define BSX_TYPE_ORIENTATION                            (3)
#define BSX_TYPE_PRESSURE                                       (6)
#define BSX_TYPE_PROXIMITY                                      (8)
#define BSX_TYPE_RELATIVE_HUMIDITY                      (12)
#define BSX_TYPE_ROTATION_VECTOR                        (11)
#define BSX_TYPE_TEMPERATURE                             (7)

/** \def Datarate Array in Hz */
#define BSX_ARRAY_DATARATE                                      { (1U), (5U), (10U), (20U), (25U), (40U), (50U), (100U), (125U), (200U) }
#define BSX_ARRAY_ACCMEASRANGE                          { (2U), (4U), (8U), (16U) }       /** \def Acc Range Array in G */
#define BSX_ARRAY_GYROMEASRANGE                         { (2048), (2000), (1000), (500), (250) }
#define BSX_ARRAY_FILTERIIRCOEFF                        { (0.0f), (0.0f), (0.0f), (0.0f), (0.0f), (0.0f), (0.35f), (0.55f), (0.0f), (0.7f) } /** filtering coefficient : 0 => no filtering*/
#define BSX_REF_ARRAY                                           { (1000U), (200U), (100U), (50U), (40U), (25U), (20U), (10U), (8U), (5U) }

/** \def Opmode Shift Defines*/
#define BSX_BITSHIFT_ACCOPMODE                          (0U)
#define BSX_BITSHIFT_MAGOPMODE                          (2U)
#define BSX_BITSHIFT_GYROOPMODE                         (4U)
#define BSX_BITSHIFT_COMPASSOPMODE                      (6U)
#define BSX_BITSHIFT_M4GOPMODE                          (8U)
#define BSX_BITSHIFT_NDOFOPMODE                         (10U)
#define BSX_BITSHIFT_FASTMAGCALIBOPMODE         (12U)
#define BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE (14U)
#define BSX_BITSHIFT_MAGCALIBSOURCE                     (16U)
#define BSX_BITSHIFT_GYROCALIBOPMODE            (18U)
#define BSX_BITSHIFT_NDOFGEORVOPMODE        (20U)

#define BSX_BITMASKING                                          (0x03U)

/** \def Working Modes */
#define BSX_WORKINGMODE_SLEEP                           (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_SLEEP << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_ACCOPMODE)) /**/
#define BSX_WORKINGMODE_ACCONLY                         (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_SLEEP << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_MAGONLY                         (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_SLEEP << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_CLASSIC << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_ACCMAG                          (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_SLEEP << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_CLASSIC << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_ACCGYRO                         (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYROACC << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_IMUPLUS                         (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYROACC << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOFIMU << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_GYROONLY                        (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYRODATA << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_MAGGYRO                         (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYRODATA << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_FAST << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_AMG                                     (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYROACCMAG << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_FAST << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))
#define BSX_WORKINGMODE_COMPASS                         (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_SLEEP << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_CLASSIC << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))              /**/
#define BSX_WORKINGMODE_M4G                                     (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_SLEEP << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_CLASSIC << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))      /**/

#define BSX_WORKINGMODE_NDOF_FMC_OFF            (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYROACCMAG << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_CLASSIC << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_REGULAR << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))          /**/
#define BSX_WORKINGMODE_NDOF                            (BSX_U32)((BSX_NDOFGRV_SLEEP << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYROACCMAG << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_FAST << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_REGULAR << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))          /**/

#define BSX_WORKINGMODE_NDOF_GEORV          (BSX_U32)((BSX_NDOFGRV_ACTIVE << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYROACCMAG << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_FAST << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_REGULAR << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))                   /**/
#define BSX_WORKINGMODE_NDOF_GEORV_FMC_OFF  (BSX_U32)((BSX_NDOFGRV_ACTIVE << BSX_BITSHIFT_NDOFGEORVOPMODE) | (BSX_GYROCALIB_GYROACCMAG << BSX_BITSHIFT_GYROCALIBOPMODE) | (BSX_CALIBSOURCE_CLASSIC << BSX_BITSHIFT_MAGCALIBSOURCE) | (BSX_CALIB_MODEOFFSETACTIVE << BSX_BITSHIFT_CLASSICALMAGCALIBOPMODE) | (BSX_CALIB_SLEEP << BSX_BITSHIFT_FASTMAGCALIBOPMODE) | (BSX_OPMODE_NDOF_REGULAR << BSX_BITSHIFT_NDOFOPMODE) | (BSX_OPMODE_NDOF_SLEEP << BSX_BITSHIFT_M4GOPMODE) | (BSX_OPMODE_SLEEP << BSX_BITSHIFT_COMPASSOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_GYROOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_MAGOPMODE) | (BSX_OPMODE_REGULAR << BSX_BITSHIFT_ACCOPMODE))             /**/

#define BSX_WORKINGMODE_DEFAULT                         BSX_WORKINGMODE_SLEEP

/** \def Orientation Sensor Modes */
/*Ndof*/
#define BSX_OPMODE_NDOF_SLEEP                           (0U)
#define BSX_OPMODE_NDOFIMU                                      (1U)
#define BSX_OPMODE_NDOF_REGULAR                         (2U)

/** \def Time related */
#define BSX_SAMPLETIMETOLERANCE                         (0.95f)   /** \def  Decreasing of RefTime by this factor => 10ms * 0.95 = 9.5ms --> 105.2Hz */

/** \Orientation sensor model */
#define BSX_OPMODE_ORIENT_SLEEP             (0U)        /** \sleep	 */
#define BSX_OPMODE_ORIENT_COMPASS           (1U)        /** \Compass */
#define BSX_OPMODE_ORIENT_M4G               (2U)        /** \M4G     */
#define BSX_OPMODE_ORIENT_IMU               (3U)        /** \IMU	 */
#define BSX_OPMODE_ORIENT_NDOF              (4U)        /** \NDOF        */

/** \Flip gesture Operation mode */
#define BSX_FLIP_GESTURE_MODE_SLEEP                     (0U)    /** \sleep	 */
#define BSX_FLIP_GESTURE_MODE_REGULAR           (1U)            /** \regular */

/** \Significant Motion Operation mode */
#define BSX_SIGNIFICANT_MOTION_SLEEP            (0U)    /** \sleep	 */
#define BSX_SIGNIFICANT_MOTION_REGULAR          (1U)    /** \regular */

/** \Pedometer Support Operation Mode */
#define BSX_PEDO_SUPPORT_SLEEP              (0U)        /**\sleep*/
#define BSX_PEDO_SUPPORT_REGULAR            (1U)        /**\regular*/

/* \Orient coordinate system*/
#define BSX_ORIENTCOORDINATESYSTEM_ANDROID      (1U)    /** Android */
#define BSX_ORIENTCOORDINATESYSTEM_WIN8         (2U)    /** Win8 */

#define BSX_COMPASSORIENTFILTER_MODE_BYPASS   (0U)
#define BSX_COMPASSORIENTFILTER_MODE_LOW      (1U)
#define BSX_COMPASSORIENTFILTER_MODE_MEDIUM   (2U)
#define BSX_COMPASSORIENTFILTER_MODE_HIGH     (3U)

#define BSX_COMPASSORIENTFILTERCOEFFCALC_MODE_BYPASS   (0U)
#define BSX_COMPASSORIENTFILTERCOEFFCALC_MODE_FORWARD  (1U)
#define BSX_COMPASSORIENTFILTERCOEFFCALC_MODE_BACKWARD (2U)

#define BSX_PREDEFINED_LEVEL_ZERO             (0U)
#define BSX_PREDEFINED_LEVEL_ONE              (1U)
#define BSX_PREDEFINED_LEVEL_TWO              (2U)
#define BSX_PREDEFINED_LEVEL_THREE            (3U)
#define BSX_PREDEFINED_LEVEL_FOUR             (4U)
#define BSX_PREDEFINED_LEVEL_FIVE             (5U)

#define BSX_PREDEFINED_LEVEL_MIN     BSX_PREDEFINED_LEVEL_ZERO
#define BSX_PREDEFINED_LEVEL_DEFAULT BSX_PREDEFINED_LEVEL_ONE
#define BSX_PREDEFINED_LEVEL_MAX     BSX_PREDEFINED_LEVEL_FIVE
#endif





































