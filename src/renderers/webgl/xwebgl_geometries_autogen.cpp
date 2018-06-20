#include "xthreejs/renderers/webgl/xwebgl_geometries_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_geometries>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_geometries>;
    template xw::xmaterialize<xthree::xwebgl_geometries>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_geometries>>;
    template class xw::xgenerator<xthree::xwebgl_geometries>;
    template xw::xgenerator<xthree::xwebgl_geometries>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_geometries>>;
#endif
