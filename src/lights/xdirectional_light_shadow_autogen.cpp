#include "xthreejs/lights/xdirectional_light_shadow_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdirectional_light_shadow>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xdirectional_light_shadow>;
    template xw::xmaterialize<xthree::xdirectional_light_shadow>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xdirectional_light_shadow>>;
    template class xw::xgenerator<xthree::xdirectional_light_shadow>;
    template xw::xgenerator<xthree::xdirectional_light_shadow>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xdirectional_light_shadow>>;
#endif
