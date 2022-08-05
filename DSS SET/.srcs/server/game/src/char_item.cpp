// Search:
	if (item->GetWearFlag() & WEARABLE_UNIQUE)
	{
		if ((GetWear(WEAR_UNIQUE1) && GetWear(WEAR_UNIQUE1)->IsSameSpecialGroup(item)) ||
			(GetWear(WEAR_UNIQUE2) && GetWear(WEAR_UNIQUE2)->IsSameSpecialGroup(item)))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("���� ������ ����ũ ������ �� ���� ���ÿ� ������ �� �����ϴ�."));
			return false;
		}

		if (marriage::CManager::instance().IsMarriageUniqueItem(item->GetVnum()) &&
			!marriage::CManager::instance().IsMarried(GetPlayerID()))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("��ȥ���� ���� ���¿��� ������ ������ �� �����ϴ�."));
			return false;
		}
	}
// Add after:
#ifdef ENABLE_DS_SET
	if ((DragonSoul_IsDeckActivated()) && (item->IsDragonSoul())) {
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("DS_DEACTIVATE_REQ"));
		return false;
	}
#endif



// Search:
	// ������ ������ �� ���� ������
	if (IS_SET(item->GetFlag(), ITEM_FLAG_IRREMOVABLE))
		return false;
// Add after:
#ifdef ENABLE_DS_SET
	if ((DragonSoul_IsDeckActivated()) && (item->IsDragonSoul())) {
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("DS_DEACTIVATE_REQ"));
		return false;
	}
#endif