#ifndef XTHREE_COMPRESSED_TEXTURE_HPP
#define XTHREE_COMPRESSED_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xtexture_autogen.hpp"

namespace xthree
{
    //
    // compressed_texture declaration
    //

    template<class D>
    class xcompressed_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xcompressed_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using compressed_texture = xw::xmaterialize<xcompressed_texture>;

    using compressed_texture_generator = xw::xgenerator<xcompressed_texture>;

    //
    // compressed_texture implementation
    //


    template <class D>
    inline void xcompressed_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcompressed_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcompressed_texture<D>::xcompressed_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcompressed_texture<D>::set_defaults()
    {
        this->_model_name() = "CompressedTextureModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xcompressed_texture));
//}
#endif