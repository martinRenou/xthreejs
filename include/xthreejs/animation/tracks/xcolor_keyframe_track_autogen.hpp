#ifndef XTHREE_COLOR_KEYFRAME_TRACK_HPP
#define XTHREE_COLOR_KEYFRAME_TRACK_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../xkeyframe_track_autogen.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // color_keyframe_track declaration
    //

    template<class D>
    class xcolor_keyframe_track : public xkeyframe_track<D>
    {
    public:

        using base_type = xkeyframe_track<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcolor_keyframe_track();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using color_keyframe_track = xw::xmaterialize<xcolor_keyframe_track>;

    using color_keyframe_track_generator = xw::xgenerator<xcolor_keyframe_track>;

    //
    // color_keyframe_track implementation
    //


    template <class D>
    inline void xcolor_keyframe_track<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcolor_keyframe_track<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcolor_keyframe_track<D>::xcolor_keyframe_track()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcolor_keyframe_track<D>::set_defaults()
    {
        this->_model_name() = "ColorKeyframeTrackModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcolor_keyframe_track>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xcolor_keyframe_track>;
        extern template xw::xmaterialize<xthree::xcolor_keyframe_track>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcolor_keyframe_track>>;
        extern template class xw::xgenerator<xthree::xcolor_keyframe_track>;
        extern template xw::xgenerator<xthree::xcolor_keyframe_track>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcolor_keyframe_track>>;
    #endif
#endif

#endif