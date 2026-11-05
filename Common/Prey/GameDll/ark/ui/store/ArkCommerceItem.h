#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkCommerceItem
// Header:  _unknown/ArkCommerceItem.h
struct ArkCommerceItem
{ // Size=40 (0x28)
	enum class Type
	{
		Type_Unknown = 0,
		Type_Category = 1,
		Type_Product = 2,
	};

	ArkCommerceItem::Type type;
	string productId;
	string name;
	string label;
	string price;

#if 0
	ArkCommerceItem();
	ArkCommerceItem(ArkCommerceItem::Type _arg0_, const char* _arg1_, const char* _arg2_, const char* _arg3_, const char* _arg4_);
#endif
};

#endif // MOONCRASH
