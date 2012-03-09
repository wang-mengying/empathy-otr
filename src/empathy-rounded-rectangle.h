/*
 * empathy-rounded-rectangle.h - Header for EmpathyRoundedRectangle
 * Copyright (C) 2011 Collabora Ltd.
 * @author Emilio Pozuelo Monfort <emilio.pozuelo@collabora.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __EMPATHY_ROUNDED_RECTANGLE_H__
#define __EMPATHY_ROUNDED_RECTANGLE_H__

#include <glib-object.h>
#include <clutter/clutter.h>

G_BEGIN_DECLS

typedef struct _EmpathyRoundedRectangle EmpathyRoundedRectangle;
typedef struct _EmpathyRoundedRectanglePriv EmpathyRoundedRectanglePriv;
typedef struct _EmpathyRoundedRectangleClass EmpathyRoundedRectangleClass;

struct _EmpathyRoundedRectangleClass {
    ClutterCairoTextureClass parent_class;
};

struct _EmpathyRoundedRectangle {
    ClutterCairoTexture parent;

    EmpathyRoundedRectanglePriv *priv;
};

GType empathy_rounded_rectangle_get_type (void);

/* TYPE MACROS */
#define EMPATHY_TYPE_ROUNDED_RECTANGLE \
  (empathy_rounded_rectangle_get_type ())
#define EMPATHY_ROUNDED_RECTANGLE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), EMPATHY_TYPE_ROUNDED_RECTANGLE, \
    EmpathyRoundedRectangle))
#define EMPATHY_ROUNDED_RECTANGLE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass), EMPATHY_TYPE_ROUNDED_RECTANGLE, \
    EmpathyRoundedRectangleClass))
#define EMPATHY_IS_ROUNDED_RECTANGLE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), EMPATHY_TYPE_ROUNDED_RECTANGLE))
#define EMPATHY_IS_ROUNDED_RECTANGLE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass), EMPATHY_TYPE_ROUNDED_RECTANGLE))
#define EMPATHY_ROUNDED_RECTANGLE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), EMPATHY_TYPE_ROUNDED_RECTANGLE, \
    EmpathyRoundedRectangleClass))

EmpathyRoundedRectangle *empathy_rounded_rectangle_new (guint width,
    guint height,
    guint round_factor);

void
empathy_rounded_rectangle_set_border_width (EmpathyRoundedRectangle *self,
    guint border_width);

void
empathy_rounded_rectangle_set_border_color (EmpathyRoundedRectangle *self,
    const ClutterColor *color);

G_END_DECLS

#endif /* #ifndef __EMPATHY_ROUNDED_RECTANGLE_H__*/
