#ifndef AL_AL_STEREO_ANGLES_H
#define AL_AL_STEREO_ANGLES_H

/*****************************************************************************/

/*
 * This extension allows any stereo source to be "steered" by setting
 * the angles at which the left and right channels should play.
 *
 * Angles are always specified in radians, anticlockwise relative to the 
 * real front (AL_SOURCE_RELATIVE is not supported).
 */
#define AL_EXT_STEREO_ANGLES "AL_EXT_STEREO_ANGLES"

/*
 * This tag can be used with alSourcefv() and two angles. The angles 
 * are specified anticlockwise relative to the real front, so a normal
 * 60degree front stage is specified with 
 * alSourcefv(sid,AL_STEREO_ANGLES,+M_PI/6,-M_PI/6).
 */
#define AL_STEREO_ANGLES 0x1030

/*****************************************************************************/

#endif /* AL_AL_STEREO_ANGLES_H */
