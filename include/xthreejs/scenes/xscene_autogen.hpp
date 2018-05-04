#ifndef XTHREE_SCENE_HPP
#define XTHREE_SCENE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // scene declaration
    //

    template<class D>
    class xscene : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, fog);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, overrideMaterial);
        XPROPERTY(bool, derived_type, autoUpdate, true);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, background, "#ffffff");


    protected:

        xscene();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using scene = xw::xmaterialize<xscene>;

    using scene_generator = xw::xgenerator<xscene>;

    //
    // scene implementation
    //


    template <class D>
    inline void xscene<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(fog, state, buffers);
        xw::set_patch_from_property(overrideMaterial, state, buffers);
        xw::set_patch_from_property(autoUpdate, state, buffers);
        xw::set_patch_from_property(background, state, buffers);
    }

    template <class D>
    inline void xscene<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(fog, patch, buffers);
        xw::set_property_from_patch(overrideMaterial, patch, buffers);
        xw::set_property_from_patch(autoUpdate, patch, buffers);
        xw::set_property_from_patch(background, patch, buffers);
    }

    template <class D>
    inline xscene<D>::xscene()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xscene<D>::set_defaults()
    {
        this->_model_name() = "SceneModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xscene));
//}
#endif