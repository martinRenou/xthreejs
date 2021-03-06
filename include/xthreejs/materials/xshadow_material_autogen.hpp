#ifndef XTHREE_SHADOW_MATERIAL_HPP
#define XTHREE_SHADOW_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xshader_material_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // shadow_material declaration
    //

    template<class D>
    class xshadow_material : public xshader_material<D>
    {
    public:

        using base_type = xshader_material<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(bool, derived_type, lights, true);
        XPROPERTY(bool, derived_type, transparent, true);
        XPROPERTY(std::string, derived_type, type, "ShadowMaterial");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xshadow_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using shadow_material = xw::xmaterialize<xshadow_material>;

    using shadow_material_generator = xw::xgenerator<xshadow_material>;

    //
    // shadow_material implementation
    //


    template <class D>
    inline void xshadow_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(transparent, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xshadow_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(transparent, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xshadow_material<D>::xshadow_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xshadow_material<D>::set_defaults()
    {
        this->_model_name() = "ShadowMaterialModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xshadow_material>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xshadow_material>;
        extern template xw::xmaterialize<xthree::xshadow_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xshadow_material>>;
        extern template class xw::xgenerator<xthree::xshadow_material>;
        extern template xw::xgenerator<xthree::xshadow_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xshadow_material>>;
    #endif
#endif

#endif