#ifndef AL_AL_FOLDBACK_H
#define AL_AL_FOLDBACK_H

#include "al.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define AL_EXT_FOLDBACK_NAME "AL_EXT_FOLDBACK"

#define AL_FOLDBACK_MODE_MONO   0x4101
#define AL_FOLDBACK_MODE_STEREO 0x4102

#define AL_FOLDBACK_EVENT_START 0x4111
#define AL_FOLDBACK_EVENT_BLOCK 0x4112
#define AL_FOLDBACK_EVENT_STOP  0x4113

/** 
 * Foldback Notes:
 *
 * This OpenAL extension provides a "foldback" facility to OpenAL,
 * allowing a mono or stereo mix of the overall OpenAL output to be
 * fed back to the originating software for further processing,
 * recording etc. It should be noted that there are better ways to
 * define such an extension, e.g. by arranging for the foldback 
 * data to be written to standard OpenAL audio buffers (see the
 * OpenAL mailing list), so this extension may become deprecated.
 * 
 * The OpenAL extension can be detected by a call to
 * alIsExtensionPresent requesting extension "AL_EXT_FOLDBACK"
 * (defined by macro AL_EXT_FOLDBACK_NAME).
 *
 * If it is present, the calls "alRequestFoldbackStart" (of type
 * LPALREQUESTFOLDBACKSTART) and "alRequestFoldbackStop" (of type
 * LPALREQUESTFOLDBACKSTOP) will be available from
 * alGetProcAddress. These calls control an asynchronous 
 * event stream to be handled by a callback function required by
 * alRequestFoldbackStart.
 * 
 * The calling software is required to provide a range of memory into
 * which foldback data will be written. This range of memory is a
 * circular buffer, divided into fixed-size blocks. Data is
 * interleaved if stereo is required. The callback function indicates
 * when a block of memory is ready for processing. The callbacks are
 * delivered asynchronously and in sequence - it is up to the calling
 * software to keep up with the data flow.
 * 
 * If the alRequestFoldbackStart call succeeds, the callback function
 * will be fed events. The first event is an AL_FOLDBACK_EVENT_START
 * event indicating that streaming has begun. Subsequent events are
 * zero or more AL_FOLDBACK_EVENT_BLOCK events indicating each block
 * as it becomes ready, with a final AL_FOLDBACK_EVENT_STOP to
 * indicate that processing has ended. The memory region should not be
 * released until an AL_FOLDBACK_EVENT_STOP event has been received
 * (normally this occurs after alRequestFoldbackStop has returned).
 */

/**
 * Foldback Callback.
 *
 * Three different "event" values are defined: AL_FOLDBACK_EVENT_START
 * indicates that streaming has begun, AL_FOLDBACK_EVENT_BLOCK
 * indicates a data block is ready and AL_FOLDBACK_EVENT_STOP
 * indicates that streaming has ended.
 *
 * The "blockIndex" value is defined only where the event is
 * AL_FOLDBACK_EVENT_BLOCK. In this context, it indicates which block
 * (indexed from zero) within the memory region provided to
 * alRequestFoldbackStart is ready. Note that the blockIndex value
 * wraps around, returning to zero when the bufferCount is reached.
 */
typedef void (AL_APIENTRY *LPALFOLDBACKCALLBACK) ( ALenum event, ALsizei blockIndex );
  
/**
 * Function name: alRequestFoldbackStart
 *
 * If this call succeeds, then it is guaranteed that the callback
 * function be called at least once with a start event and once with a
 * stop event. 
 * 
 * If this call sets AL_INVALID_VALUE, this may be because the
 * blockCount and blockLength are not large enough for the current
 * renderer, so it may be worth trying a larger value.
 * 
 * Data is written into the region of memory starting at bufferMemory
 * in sequential blocks of floats with count blockLength, or twice
 * blockLength if stereo is used (data is interleaved). After each
 * block is written, a callback is queued for asynchronous delivery.
 * 
 * "foldbackMode" may be AL_FOLDBACK_MODE_MONO for mono or
 * AL_FOLDBACK_MODE_STEREO for interleaved stereo.
 *
 * "blockCount" indicates the number of blocks of audio that should
 * be available at bufferMemory. This must be at least two.
 * 
 * "blockLength" indicates the number of frames of audio that should
 * be available within each block. Note that there will be two samples
 * per frame if stereo is in use.
 *
 * "bufferMemory" indicates the start of the region of memory,
 * provided by the calling software, which will be used for the shared
 * circular buffer. It is required to allow space for a number of
 * floats: blockLength*blockCount floats if foldbackMode is
 * AL_FOLDBACK_MODE_MONO or blockLength*2*blockCount floats if
 * foldbackMode is AL_FOLDBACK_MODE_STEREO. The memory is owned by the
 * calling software and should not be deleted until an
 * AL_FOLDBACK_EVENT_STOP event has been received.
 *
 * "callback" is the pointer to a function provided by the calling
 * software that will handle foldback streaming events (see above).
 */
typedef void (AL_APIENTRY *LPALREQUESTFOLDBACKSTART) ( 
  ALenum               foldbackMode, 
  ALsizei              blockCount, 
  ALsizei              blockLength, 
  ALfloat *            bufferMemory, 
  LPALFOLDBACKCALLBACK callback 
);

/**
 * Function name: alRequestFoldbackStop
 *
 * This call requests an end to foldback. 
 * 
 * Note that this call does not stop foldback immediately - any queued
 * blocks must still be processed. A stop event
 * (AL_FOLDBACK_EVENT_STOP) will be received to indicate that the
 * foldback has actually completed and buffer memory should not be
 * freed before then.
 */
typedef void (AL_APIENTRY *LPALREQUESTFOLDBACKSTOP) ( void );

#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif /* AL_AL_FOLDBACK_H */
