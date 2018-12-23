
#ifndef AFX_LIGHT_H__ACA1A2A6_E72D_4EBC_B919_5C0AC538F456__INCLUDED_
#define AFX_LIGHT_H__ACA1A2A6_E72D_4EBC_B919_5C0AC538F456__INCLUDED_

//��Դ��

#include "Vector3.h"

NS_MATH3D_BEGIN

class Vector3;
class ColorRGBA;

class MATH3D_API BaseLight
{
public:
	//�����Դ������
	enum LightType
	{
		// ���Դ
		LT_POINT = 0,
		// �����Թ�Դ
		LT_DIRECTIONAL = 1,
		// SPOT��Դ
		LT_SPOTLIGHT = 2,
        //������Դ
        LT_AMBIENT = 3
	};
    
    //�ƹ��־
    enum LightFlag
    {
        LIGHT0 = 1,
        LIGHT1 = 1 << 1,
        LIGHT2 = 1 << 2,
        LIGHT3 = 1 << 3,
        LIGHT4 = 1 << 4,
        LIGHT5 = 1 << 5,
        LIGHT6 = 1 << 6,
        LIGHT7 = 1 << 7,
        LIGHT8 = 1 << 8,
        LIGHT9 = 1 << 9,
        LIGHT10 = 1 << 10,
        LIGHT11 = 1 << 11,
        LIGHT12 = 1 << 12,
        LIGHT13 = 1 << 13,
        LIGHT14 = 1 << 14,
        LIGHT15 = 1 << 15,
    };

    
    BaseLight();
    virtual ~BaseLight();

    virtual LightType getLightType() const = 0;
    
    /** ǿ��  */
    float getIntensity() const { return mIntensity; }
    void setIntensity(float intensity);
    
    LightFlag getLightFlag() const { return mLightFlag; }
    void setLightFlag(LightFlag flag) { mLightFlag = flag; }
    
    /**
     * �Ƿ����ù�Դ
     */
    void setEnabled(bool enabled) { mEnabled = enabled; }
    bool isEnabled() const { return mEnabled; }
    
    virtual void onEnter();
    virtual void onExit();
    
protected:
    void setRotationFromDirection( const Vector3 &direction );
    
protected:
    float       mIntensity;
    LightFlag   mLightFlag;
    bool        mEnabled;
};

class MATH3D_API DirectionLight : public BaseLight
{
public:
    /**
     *  ���������Թ�Դ
     *
     *  @param direction ����
     *  @param color     ��ɫ
     *
     *  @return
     */
    static DirectionLight* create(const Vector3 &direction, const ColorRGBA& color);
    
    virtual LightType getLightType() const { return BaseLight::LT_DIRECTIONAL; }
    
    /**
     * Sets the Direction in parent.
     *
     * @param dir The Direction in parent.
     */
    void setDirection(const Vector3 &dir);
    
    /**
     * Returns the Direction in parent.
     */
    Vector3 getDirection() const;
    
    /**
     * Returns direction in world.
     */
    Vector3 getDirectionInWorld() const;
    
	DirectionLight(){}
	virtual ~DirectionLight(){}
    
};


NS_MATH3D_END

#endif // 
