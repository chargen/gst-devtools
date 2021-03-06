/* GstValidate
 *
 * Copyright (c) 2012, Collabora Ltd
 *    Author: Thibault Saunier <thibault.saunier@collabora.com>
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
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef GST_VALIDATE_MEDIA_DESCRIPTOR_PARSER_h
#define GST_VALIDATE_MEDIA_DESCRIPTOR_PARSER_h

#include <glib.h>
#include <glib-object.h>
#include <gst/gst.h>
#include "media-descriptor.h"

G_BEGIN_DECLS

GType gst_validate_media_descriptor_parser_get_type (void);

#define GST_TYPE_VALIDATE_MEDIA_DESCRIPTOR_PARSER            (gst_validate_media_descriptor_parser_get_type ())
#define GST_VALIDATE_MEDIA_DESCRIPTOR_PARSER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GST_TYPE_VALIDATE_MEDIA_DESCRIPTOR_PARSER, GstValidateMediaDescriptorParser))
#define GST_VALIDATE_MEDIA_DESCRIPTOR_PARSER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GST_TYPE_VALIDATE_MEDIA_DESCRIPTOR_PARSER, GstValidateMediaDescriptorParserClass))
#define GST_IS_VALIDATE_MEDIA_DESCRIPTOR_PARSER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GST_TYPE_VALIDATE_MEDIA_DESCRIPTOR_PARSER))
#define GST_IS_VALIDATE_MEDIA_DESCRIPTOR_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GST_TYPE_VALIDATE_MEDIA_DESCRIPTOR_PARSER))
#define GST_VALIDATE_MEDIA_DESCRIPTOR_PARSER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_VALIDATE_MEDIA_DESCRIPTOR_PARSER, GstValidateMediaDescriptorParserClass))

typedef struct _GstValidateMediaDescriptorParserPrivate GstValidateMediaDescriptorParserPrivate;


typedef struct {
  GstValidateMediaDescriptor parent;

  GstValidateMediaDescriptorParserPrivate *priv;

} GstValidateMediaDescriptorParser;

typedef struct {

  GstValidateMediaDescriptorClass parent;

} GstValidateMediaDescriptorParserClass;

GstValidateMediaDescriptorParser * gst_validate_media_descriptor_parser_new (GstValidateRunner *runner,
                                                            const gchar * xmlpath,
                                                            GError **error);
GstValidateMediaDescriptorParser *
gst_validate_media_descriptor_parser_new_from_xml                   (GstValidateRunner * runner,
                                                            const gchar * xml,
                                                            GError ** error);
gchar * gst_validate_media_descriptor_parser_get_xml_path        (GstValidateMediaDescriptorParser *parser);
gboolean gst_validate_media_descriptor_parser_add_stream         (GstValidateMediaDescriptorParser *parser,
                                                                  GstPad *pad);
gboolean gst_validate_media_descriptor_parser_add_taglist        (GstValidateMediaDescriptorParser *parser,
                                                                  GstTagList *taglist);
gboolean gst_validate_media_descriptor_parser_all_stream_found   (GstValidateMediaDescriptorParser *parser);
gboolean gst_validate_media_descriptor_parser_all_tags_found     (GstValidateMediaDescriptorParser *parser);

G_END_DECLS

#endif /* GST_VALIDATE_MEDIA_DESCRIPTOR_PARSER_h */
