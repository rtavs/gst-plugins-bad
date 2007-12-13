/*
 * GStreamer
 * Copyright 2007 Edgard Lima <edgard.lima@indt.org.br>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, the contents of this file may be used under the
 * GNU Lesser General Public License Version 2.1 (the "LGPL"), in
 * which case the following provisions apply instead of the ones
 * mentioned above:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __METADATAMUX_PNG_H__
#define __METADATAMUX_PNG_H__

#include <gst/base/gstadapter.h>

#include "metadatatypes.h"

G_BEGIN_DECLS

typedef enum _tag_PngMuxState
{
  PNG_MUX_NULL,
  PNG_MUX_READING,
  PNG_MUX_JUMPING,
  PNG_MUX_XMP,
  PNG_MUX_DONE
} PngMuxState;


typedef struct _tag_PngMuxData
{
  PngMuxState state;

  MetadataChunkArray * strip_chunks;
  MetadataChunkArray * inject_chunks;

} PngMuxData;


extern void
metadatamux_png_init (PngMuxData * png_data,
    MetadataChunkArray * strip_chunks, MetadataChunkArray * inject_chunks);

extern void metadatamux_png_dispose (PngMuxData * png_data);

extern void metadatamux_png_lazy_update (PngMuxData * png_data);

extern MetadataParsingReturn
metadatamux_png_parse (PngMuxData * png_data, guint8 * buf,
    guint32 * bufsize, const guint32 offset, guint8 ** next_start, guint32 * next_size);

G_END_DECLS
#endif /* __METADATAMUX_PNG_H__ */
