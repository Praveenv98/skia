/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkCanvas.h"
#include "SkSVGEllipse.h"
#include "SkSVGRenderContext.h"
#include "SkSVGValue.h"

SkSVGEllipse::SkSVGEllipse() : INHERITED(SkSVGTag::kEllipse) {}

void SkSVGEllipse::setCx(const SkSVGLength& cx) {
    fCx = cx;
}

void SkSVGEllipse::setCy(const SkSVGLength& cy) {
    fCy = cy;
}

void SkSVGEllipse::setRx(const SkSVGLength& rx) {
    fRx = rx;
}

void SkSVGEllipse::setRy(const SkSVGLength& ry) {
    fRy = ry;
}

void SkSVGEllipse::onSetAttribute(SkSVGAttribute attr, const SkSVGValue& v) {
    switch (attr) {
    case SkSVGAttribute::kCx:
        if (const auto* cx = v.as<SkSVGLengthValue>()) {
            this->setCx(*cx);
        }
        break;
    case SkSVGAttribute::kCy:
        if (const auto* cy = v.as<SkSVGLengthValue>()) {
            this->setCy(*cy);
        }
        break;
    case SkSVGAttribute::kRx:
        if (const auto* rx = v.as<SkSVGLengthValue>()) {
            this->setRx(*rx);
        }
        break;
    case SkSVGAttribute::kRy:
        if (const auto* ry = v.as<SkSVGLengthValue>()) {
            this->setRy(*ry);
        }
        break;
    default:
        this->INHERITED::onSetAttribute(attr, v);
    }
}

void SkSVGEllipse::onDraw(SkCanvas* canvas, const SkSVGLengthContext& lctx,
                          const SkPaint& paint, SkPath::FillType) const {
    const auto cx = lctx.resolve(fCx, SkSVGLengthContext::LengthType::kHorizontal);
    const auto cy = lctx.resolve(fCy, SkSVGLengthContext::LengthType::kVertical);
    const auto rx = lctx.resolve(fRx, SkSVGLengthContext::LengthType::kHorizontal);
    const auto ry = lctx.resolve(fRy, SkSVGLengthContext::LengthType::kVertical);

    if (rx > 0 && ry > 0) {
        canvas->drawOval(SkRect::MakeXYWH(cx - rx, cy - ry, rx * 2, ry * 2), paint);
    }
}
