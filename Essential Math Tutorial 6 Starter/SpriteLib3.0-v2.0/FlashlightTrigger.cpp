#include "FlashlightTrigger.h"
#include "ECS.h"
#include "Player.h"

void FlashlightTrigger::OnTrigger()
{
	Trigger::OnTrigger();
}

void FlashlightTrigger::OnEnter(int entity)
{
	Trigger::OnEnter(entity);
	if (ECS::GetComponent<Player>(m_targetEntities[0]).m_flashlight)
	{
		
		if (ECS::GetComponent<CanDamage>(entity).m_canbestun)
			{
				auto& body = ECS::GetComponent<PhysicsBody>(entity);
				//"stun" ghost
				body.GetBody()->SetLinearVelocity(b2Vec2(0, 0));

				auto& ghost = ECS::GetComponent<CanDamage>(entity);
				ghost.m_candamage = false;
				//ghost.m_stun = true;
			}
		}
	}


void FlashlightTrigger::OnExit()
{
	Trigger::OnExit();
}
