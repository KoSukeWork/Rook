#ifndef AL_AL_BFORMAT_H
#define AL_AL_BFORMAT_H

/*
 * This extension indicates support for the AL_FORMAT_BFORMAT2D_8,
 * AL_FORMAT_BFORMAT2D_16, AL_FORMAT_BFORMAT2D_FLOAT32, 
 * AL_FORMAT_BFORMAT3D_8, AL_FORMAT_BFORMAT3D_16 and 
 * AL_FORMAT_BFORMAT3D_FLOAT32 buffer formats.
 * 
 * These provide 2D (WXY) and 3D (WXYZ) 8bit int, 16bit int and ALfloat 
 * support for Ambisonic three- or four-channel B-Format (using W X Y Z 
 * channel ordering, encoded as the first three or four channels of 
 * Furse-Malham higher order Ambisonics). Use of these formats indicate 
 * that sources are Ambisonic sources. Such sources can be oriented via 
 * alSourcefv() using the AL_ORIENTATION tag, which takes the same 
 * parameters as alListenerfv(AL_ORIENTATION,...). Such sources DO 
 * support AL_SOURCE_RELATIVE and the soundfield will rotate to reflect
 * the listener's orientation if this is off (the default). Other
 * behaviour is as for stereo or multichannel assets.
 *
 * Note that Ambisonics orients X, Y and Z axes in a different way to
 * OpenAL. For clarity, we ignore the Ambisonic coordinate system in
 * the API and stick to the OpenAL one when specifying orientation,
 * making sure that the front of the Ambisonic soundfield (actually 
 * Ambisonic +X) matches the front of the OpenAL coordinate system 
 * (-Z by default) etc. For instance, if the orientation of the source 
 * is set so that the "at" vector is to the left, then the front of 
 * the B-Format soundfield will be presented to the left.
 */
#define AL_EXT_BFORMAT_NAME "AL_EXT_BFORMAT"

#define AL_FORMAT_BFORMAT2D_8           0x20021
#define AL_FORMAT_BFORMAT2D_16          0x20022
#define AL_FORMAT_BFORMAT2D_FLOAT32     0x20023
#define AL_FORMAT_BFORMAT3D_8           0x20031
#define AL_FORMAT_BFORMAT3D_16          0x20032
#define AL_FORMAT_BFORMAT3D_FLOAT32     0x20033

#endif /* AL_AL_BFORMAT_H */
