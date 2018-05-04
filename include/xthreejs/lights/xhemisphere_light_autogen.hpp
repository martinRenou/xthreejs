#ifndef XTHREE_HEMISPHERE_LIGHT_HPP
#define XTHREE_HEMISPHERE_LIGHT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xlight_autogen.hpp"

namespace xthree
{
    //
    // hemisphere_light declaration
    //

    template<class D>
    class xhemisphere_light : public xlight<D>
    {
    public:

        using base_type = xlight<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::html_color, derived_type, groundColor, "#000000");


    protected:

        xhemisphere_light();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using hemisphere_light = xw::xmaterialize<xhemisphere_light>;

    using hemisphere_light_generator = xw::xgenerator<xhemisphere_light>;

    //
    // hemisphere_light implementation
    //


    template <class D>
    inline void xhemisphere_light<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(groundColor, state, buffers);
    }

    template <class D>
    inline void xhemisphere_light<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(groundColor, patch, buffers);
    }

    template <class D>
    inline xhemisphere_light<D>::xhemisphere_light()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xhemisphere_light<D>::set_defaults()
    {
        this->_model_name() = "HemisphereLightModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xhemisphere_light));
//}
#endif