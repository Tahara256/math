#include <math/color-3-b.h>

Math::Color3B::Color3B() : Math::Color3B(GetElemMax(), GetElemMax(), GetElemMax())
{
}

Math::Color3B::Color3B(Elem r, Elem g, Elem b) : m_r(r), m_g(g), m_b(b)
{
}

Math::Color3B::Elem Math::Color3B::GetR() const
{
    return m_r;
}

Math::Color3B::Elem Math::Color3B::GetG() const
{
    return m_g;
}

Math::Color3B::Elem Math::Color3B::GetB() const
{
    return m_b;
}

void Math::Color3B::SetR(Elem r)
{
    m_r = r;
}

void Math::Color3B::SetG(Elem g)
{
    m_g = g;
}

void Math::Color3B::SetB(Elem b)
{
    m_b = b;
}

Math::Color3F Math::Color3B::ToColor3F() const noexcept
{
    using FloatElem = Math::Color3F::Elem;
    constexpr static auto FloatElemMax = static_cast<FloatElem>(GetElemMax());
    return  { GetR() / FloatElemMax, GetG() / FloatElemMax, GetB() / FloatElemMax };
}

Math::Color3B const Math::Color3B::Black{ 0, 0, 0 };
Math::Color3B const Math::Color3B::Dimgray{ 105, 105, 105 };
Math::Color3B const Math::Color3B::Gray{ 128, 128, 128 };
Math::Color3B const Math::Color3B::Darkgray{ 169, 169, 169 };
Math::Color3B const Math::Color3B::Silver{ 192, 192, 192 };
Math::Color3B const Math::Color3B::Lightgrey{ 211, 211, 211 };
Math::Color3B const Math::Color3B::Gainsboro{ 220, 220, 220 };
Math::Color3B const Math::Color3B::Whitesmoke{ 245, 245, 245 };
Math::Color3B const Math::Color3B::White{ 255, 255, 255 };
Math::Color3B const Math::Color3B::Snow{ 255, 250, 250 };
Math::Color3B const Math::Color3B::Ghostwhite{ 248, 248, 255 };
Math::Color3B const Math::Color3B::Floralwhite{ 255, 250, 240 };
Math::Color3B const Math::Color3B::Linen{ 250, 240, 230 };
Math::Color3B const Math::Color3B::Antiquewhite{ 250, 235, 215 };
Math::Color3B const Math::Color3B::Papayawhip{ 255, 239, 213 };
Math::Color3B const Math::Color3B::Blanchedalmond{ 255, 235, 205 };
Math::Color3B const Math::Color3B::Bisque{ 255, 228, 196 };
Math::Color3B const Math::Color3B::Moccasin{ 255, 228, 181 };
Math::Color3B const Math::Color3B::Navajowhite{ 255, 222, 173 };
Math::Color3B const Math::Color3B::Peachpuff{ 255, 218, 185 };
Math::Color3B const Math::Color3B::Mistyrose{ 255, 228, 225 };
Math::Color3B const Math::Color3B::Lavenderblush{ 255, 240, 245 };
Math::Color3B const Math::Color3B::Seashell{ 255, 245, 238 };
Math::Color3B const Math::Color3B::Oldlace{ 253, 245, 230 };
Math::Color3B const Math::Color3B::Ivory{ 255, 255, 240 };
Math::Color3B const Math::Color3B::Honeydew{ 240, 255, 240 };
Math::Color3B const Math::Color3B::Mintcream{ 245, 255, 250 };
Math::Color3B const Math::Color3B::Azure{ 240, 255, 255 };
Math::Color3B const Math::Color3B::Aliceblue{ 240, 248, 255 };
Math::Color3B const Math::Color3B::Lavender{ 230, 230, 250 };
Math::Color3B const Math::Color3B::Lightsteelblue{ 176, 196, 222 };
Math::Color3B const Math::Color3B::Lightslategray{ 119, 136, 153 };
Math::Color3B const Math::Color3B::Slategray{ 112, 128, 144 };
Math::Color3B const Math::Color3B::Steelblue{ 70, 130, 180 };
Math::Color3B const Math::Color3B::Royalblue{ 65, 105, 225 };
Math::Color3B const Math::Color3B::Midnightblue{ 25, 25, 112 };
Math::Color3B const Math::Color3B::Navy{ 0, 0, 128 };
Math::Color3B const Math::Color3B::Darkblue{ 0, 0, 139 };
Math::Color3B const Math::Color3B::Mediumblue{ 0, 0, 205 };
Math::Color3B const Math::Color3B::Blue{ 0, 0, 255 };
Math::Color3B const Math::Color3B::Dodgerblue{ 30, 144, 255 };
Math::Color3B const Math::Color3B::Cornflowerblue{ 100, 149, 237 };
Math::Color3B const Math::Color3B::Deepskyblue{ 0, 191, 255 };
Math::Color3B const Math::Color3B::Lightskyblue{ 135, 206, 250 };
Math::Color3B const Math::Color3B::Skyblue{ 135, 206, 235 };
Math::Color3B const Math::Color3B::Lightblue{ 173, 216, 230 };
Math::Color3B const Math::Color3B::Powderblue{ 176, 224, 230 };
Math::Color3B const Math::Color3B::Paleturquoise{ 175, 238, 238 };
Math::Color3B const Math::Color3B::Lightcyan{ 224, 255, 255 };
Math::Color3B const Math::Color3B::Cyan{ 0, 255, 255 };
Math::Color3B const Math::Color3B::Aqua{ 0, 255, 255 };
Math::Color3B const Math::Color3B::Turquoise{ 64, 224, 208 };
Math::Color3B const Math::Color3B::Mediumturquoise{ 72, 209, 204 };
Math::Color3B const Math::Color3B::Darkturquoise{ 0, 206, 209 };
Math::Color3B const Math::Color3B::Lightseagreen{ 32, 178, 170 };
Math::Color3B const Math::Color3B::Cadetblue{ 95, 158, 160 };
Math::Color3B const Math::Color3B::Darkcyan{ 0, 139, 139 };
Math::Color3B const Math::Color3B::Teal{ 0, 128, 128 };
Math::Color3B const Math::Color3B::Darkslategray{ 47, 79, 79 };
Math::Color3B const Math::Color3B::Darkgreen{ 0, 100, 0 };
Math::Color3B const Math::Color3B::Green{ 0, 128, 0 };
Math::Color3B const Math::Color3B::Forestgreen{ 34, 139, 34 };
Math::Color3B const Math::Color3B::Seagreen{ 46, 139, 87 };
Math::Color3B const Math::Color3B::Mediumseagreen{ 60, 179, 113 };
Math::Color3B const Math::Color3B::Mediumaquamarine{ 102, 205, 170 };
Math::Color3B const Math::Color3B::Darkseagreen{ 143, 188, 143 };
Math::Color3B const Math::Color3B::Aquamarine{ 127, 255, 212 };
Math::Color3B const Math::Color3B::Palegreen{ 152, 251, 152 };
Math::Color3B const Math::Color3B::Lightgreen{ 144, 238, 144 };
Math::Color3B const Math::Color3B::Springgreen{ 0, 255, 127 };
Math::Color3B const Math::Color3B::Mediumspringgreen{ 0, 250, 154 };
Math::Color3B const Math::Color3B::Lawngreen{ 124, 252, 0 };
Math::Color3B const Math::Color3B::Chartreuse{ 127, 255, 0 };
Math::Color3B const Math::Color3B::Greenyellow{ 173, 255, 47 };
Math::Color3B const Math::Color3B::Lime{ 0, 255, 0 };
Math::Color3B const Math::Color3B::Limegreen{ 50, 205, 50 };
Math::Color3B const Math::Color3B::Yellowgreen{ 154, 205, 50 };
Math::Color3B const Math::Color3B::Darkolivegreen{ 85, 107, 47 };
Math::Color3B const Math::Color3B::Olivedrab{ 107, 142, 35 };
Math::Color3B const Math::Color3B::Olive{ 128, 128, 0 };
Math::Color3B const Math::Color3B::Darkkhaki{ 189, 183, 107 };
Math::Color3B const Math::Color3B::Palegoldenrod{ 238, 232, 170 };
Math::Color3B const Math::Color3B::Cornsilk{ 255, 248, 220 };
Math::Color3B const Math::Color3B::Beige{ 245, 245, 220 };
Math::Color3B const Math::Color3B::Lightyellow{ 255, 255, 224 };
Math::Color3B const Math::Color3B::Lightgoldenrodyellow{ 250, 250, 210 };
Math::Color3B const Math::Color3B::Lemonchiffon{ 255, 250, 205 };
Math::Color3B const Math::Color3B::Wheat{ 245, 222, 179 };
Math::Color3B const Math::Color3B::Burlywood{ 222, 184, 135 };
Math::Color3B const Math::Color3B::Tan{ 210, 180, 140 };
Math::Color3B const Math::Color3B::Khaki{ 240, 230, 140 };
Math::Color3B const Math::Color3B::Yellow{ 255, 255, 0 };
Math::Color3B const Math::Color3B::Gold{ 255, 215, 0 };
Math::Color3B const Math::Color3B::Orange{ 255, 165, 0 };
Math::Color3B const Math::Color3B::Sandybrown{ 244, 164, 96 };
Math::Color3B const Math::Color3B::Darkorange{ 255, 140, 0 };
Math::Color3B const Math::Color3B::Goldenrod{ 218, 165, 32 };
Math::Color3B const Math::Color3B::Peru{ 205, 133, 63 };
Math::Color3B const Math::Color3B::Darkgoldenrod{ 184, 134, 11 };
Math::Color3B const Math::Color3B::Chocolate{ 210, 105, 30 };
Math::Color3B const Math::Color3B::Sienna{ 160, 82, 45 };
Math::Color3B const Math::Color3B::Saddlebrown{ 139, 69, 19 };
Math::Color3B const Math::Color3B::Maroon{ 128, 0, 0 };
Math::Color3B const Math::Color3B::Darkred{ 139, 0, 0 };
Math::Color3B const Math::Color3B::Brown{ 165, 42, 42 };
Math::Color3B const Math::Color3B::Firebrick{ 178, 34, 34 };
Math::Color3B const Math::Color3B::Indianred{ 205, 92, 92 };
Math::Color3B const Math::Color3B::Rosybrown{ 188, 143, 143 };
Math::Color3B const Math::Color3B::Darksalmon{ 233, 150, 122 };
Math::Color3B const Math::Color3B::Lightcoral{ 240, 128, 128 };
Math::Color3B const Math::Color3B::Salmon{ 250, 128, 114 };
Math::Color3B const Math::Color3B::Lightsalmon{ 255, 160, 122 };
Math::Color3B const Math::Color3B::Coral{ 255, 127, 80 };
Math::Color3B const Math::Color3B::Tomato{ 255, 99, 71 };
Math::Color3B const Math::Color3B::Orangered{ 255, 69, 0 };
Math::Color3B const Math::Color3B::Red{ 255, 0, 0 };
Math::Color3B const Math::Color3B::Crimson{ 220, 20, 60 };
Math::Color3B const Math::Color3B::Mediumvioletred{ 199, 21, 133 };
Math::Color3B const Math::Color3B::Deeppink{ 255, 20, 147 };
Math::Color3B const Math::Color3B::Hotpink{ 255, 105, 180 };
Math::Color3B const Math::Color3B::Palevioletred{ 219, 112, 147 };
Math::Color3B const Math::Color3B::Pink{ 255, 192, 203 };
Math::Color3B const Math::Color3B::Lightpink{ 255, 182, 193 };
Math::Color3B const Math::Color3B::Thistle{ 216, 191, 216 };
Math::Color3B const Math::Color3B::Magenta{ 255, 0, 255 };
Math::Color3B const Math::Color3B::Fuchsia{ 255, 0, 255 };
Math::Color3B const Math::Color3B::Violet{ 238, 130, 238 };
Math::Color3B const Math::Color3B::Plum{ 221, 160, 221 };
Math::Color3B const Math::Color3B::Orchid{ 218, 112, 214 };
Math::Color3B const Math::Color3B::Mediumorchid{ 186, 85, 211 };
Math::Color3B const Math::Color3B::Darkorchid{ 153, 50, 204 };
Math::Color3B const Math::Color3B::Darkviolet{ 148, 0, 211 };
Math::Color3B const Math::Color3B::Darkmagenta{ 139, 0, 139 };
Math::Color3B const Math::Color3B::Purple{ 128, 0, 128 };
Math::Color3B const Math::Color3B::Indigo{ 75, 0, 130 };
Math::Color3B const Math::Color3B::Darkslateblue{ 72, 61, 139 };
Math::Color3B const Math::Color3B::Blueviolet{ 138, 43, 226 };
Math::Color3B const Math::Color3B::Mediumpurple{ 147, 112, 219 };
Math::Color3B const Math::Color3B::Slateblue{ 106, 90, 205 };
Math::Color3B const Math::Color3B::Mediumslateblue{ 123, 104, 238 };

std::ostream & Math::operator << (std::ostream & lhs, Color3B const & rhs)
{
    // Œ^ˆø”‚ªcharŒ^‚¾‚Á‚½ê‡‚ÉA”’l‚Åo—Í‚·‚é‚½‚ß‚Éstd::to_string()‚ð’Ê‚·
    return lhs << "(r:"
        << std::to_string(rhs.GetR()) << ", g:"
        << std::to_string(rhs.GetG()) << ", b:"
        << std::to_string(rhs.GetB()) << ")";
}
