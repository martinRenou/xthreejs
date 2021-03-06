#ifndef XTHREE_QUATERNION_HPP
#define XTHREE_QUATERNION_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // quaternion declaration
    //

    template<class D>
    class xquaternion : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, x, 0);
        XPROPERTY(double, derived_type, y, 0);
        XPROPERTY(double, derived_type, z, 0);
        XPROPERTY(double, derived_type, w, 1);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xquaternion();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using quaternion = xw::xmaterialize<xquaternion>;

    using quaternion_generator = xw::xgenerator<xquaternion>;

    //
    // quaternion implementation
    //


    template <class D>
    inline void xquaternion<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(x, state, buffers);
        xw::set_patch_from_property(y, state, buffers);
        xw::set_patch_from_property(z, state, buffers);
        xw::set_patch_from_property(w, state, buffers);
    }

    template <class D>
    inline void xquaternion<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(x, patch, buffers);
        xw::set_property_from_patch(y, patch, buffers);
        xw::set_property_from_patch(z, patch, buffers);
        xw::set_property_from_patch(w, patch, buffers);
    }

    template <class D>
    inline xquaternion<D>::xquaternion()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xquaternion<D>::set_defaults()
    {
        this->_model_name() = "QuaternionModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xquaternion>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xquaternion>;
        extern template xw::xmaterialize<xthree::xquaternion>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xquaternion>>;
        extern template class xw::xgenerator<xthree::xquaternion>;
        extern template xw::xgenerator<xthree::xquaternion>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xquaternion>>;
    #endif
#endif

#endif