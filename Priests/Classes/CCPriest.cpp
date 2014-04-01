#include "CCPriest.h"
USING_NS_CC;

CCPriest::CCPriest(void)
{
}

CCPriest::~CCPriest(void)
{
}

CCPriest* CCPriest::createWithVoid()
{
	CCPriest* pCCPriest = CCPriest::create();

	//��ȡplist
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Priests_0.plist", "Priests_0.png");

	//����վ������
	CCArray *frames = CCArray::create();
	for( int i=0; i<6; i++ )
	{
		char pngName[30];
		sprintf(pngName, "Priests_0%d.png", i+1);
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pngName);
		frames->addObject(frame);
	}
	CCAnimation* pStand = CCAnimation::createWithSpriteFrames(frames, 1./6);
	frames->release();

	pCCPriest->setScaleX(-0.8);
	pCCPriest->setScaleY(0.8);
	pCCPriest->m_pStand = CCAnimate::create(pStand);
	pCCPriest->runAction(CCRepeatForever::create(pCCPriest->m_pStand));

	return pCCPriest;
}

bool CCPriest::containsTouchLocation(CCPoint touchPoint)
{
	return this->boundingBox().containsPoint(touchPoint);
}