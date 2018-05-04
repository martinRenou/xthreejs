#ifndef XTHREE_LIGHT_SHADOW_HPP
#define XTHREE_LIGHT_SHADOW_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // light_shadow declaration
    //

    template<class D>
    class xlight_shadow : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::xholder<xthree_widget>, derived_type, camera, object3d());
        XPROPERTY(double, derived_type, bias, 0);
        XPROPERTY(vector2, derived_type, mapSize, vector2({512,512}));
        XPROPERTY(double, derived_type, radius, 1);


    protected:

        xlight_shadow();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using light_shadow = xw::xmaterialize<xlight_shadow>;

    using light_shadow_generator = xw::xgenerator<xlight_shadow>;

    //
    // light_shadow implementation
    //


    template <class D>
    inline void xlight_shadow<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(camera, state, buffers);
        xw::set_patch_from_property(bias, state, buffers);
        xw::set_patch_from_property(mapSize, state, buffers);
        xw::set_patch_from_property(radius, state, buffers);
    }

    template <class D>
    inline void xlight_shadow<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(camera, patch, buffers);
        xw::set_property_from_patch(bias, patch, buffers);
        xw::set_property_from_patch(mapSize, patch, buffers);
        xw::set_property_from_patch(radius, patch, buffers);
    }

    template <class D>
    inline xlight_shadow<D>::xlight_shadow()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlight_shadow<D>::set_defaults()
    {
        this->_model_name() = "LightShadowModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xlight_shadow));
//}
#endif