#ifndef XTHREE_CUBE_TEXTURE_LOADER_HPP
#define XTHREE_CUBE_TEXTURE_LOADER_HPP

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
    // cube_texture_loader declaration
    //

    template<class D>
    class xcube_texture_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xcube_texture_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cube_texture_loader = xw::xmaterialize<xcube_texture_loader>;

    using cube_texture_loader_generator = xw::xgenerator<xcube_texture_loader>;

    //
    // cube_texture_loader implementation
    //


    template <class D>
    inline void xcube_texture_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcube_texture_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcube_texture_loader<D>::xcube_texture_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcube_texture_loader<D>::set_defaults()
    {
        this->_model_name() = "CubeTextureLoaderModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xcube_texture_loader));
//}
#endif