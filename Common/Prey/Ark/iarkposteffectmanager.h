// Header file automatically created from a PDB.

#pragma once

// Header: Exact
// Prey/Ark/iarkposteffectmanager.h
class TArkPostEffectValue // Id=8003994 Size=24
{
public:
	struct ExtractType : public boost::static_visitor<enum EArkPostEffectDataType> // Id=8003995 Size=1
	{
	};

	struct IsEqual : public boost::static_visitor<bool> // Id=8003997 Size=1
	{
	};

	boost::variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<6>,bool,boost::mpl::l_item<boost::mpl::long_<5>,int,boost::mpl::l_item<boost::mpl::long_<4>,float,boost::mpl::l_item<boost::mpl::long_<3>,Vec3,boost::mpl::l_item<boost::mpl::long_<2>,Vec4,boost::mpl::l_item<boost::mpl::long_<1>,string,boost::mpl::l_end>>>>>>>> m_variant;
	
	TArkPostEffectValue(TArkPostEffectValue const &_rhs);
	TArkPostEffectValue &operator=(TArkPostEffectValue const &_rhs) { return FoperatorEq(this,_rhs); }
	
#if 0
	bool operator==(TArkPostEffectValue const &arg0) const;
	bool operator!=(TArkPostEffectValue const &arg0) const;
	EArkPostEffectDataType GetType() const;
#endif
	
	static inline auto FoperatorEq = PreyFunction<TArkPostEffectValue &(TArkPostEffectValue *const _this, TArkPostEffectValue const &_rhs)>(0x13D10F0);
};

