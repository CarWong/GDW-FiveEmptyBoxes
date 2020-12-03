#include "MoveDownTrigger.h"
#include "ECS.h"

void MoveDownTrigger::OnTrigger()
{
	Trigger::OnTrigger();
	auto& object = ECS::GetComponent<MoveDown>(m_targetEntities[0]);
	object.moveDown = true;
}

void MoveDownTrigger::OnEnter(int entity)
{
	Trigger::OnEnter(entity);
	auto& object = ECS::GetComponent<MoveDown>(m_targetEntities[0]);
	object.moveDown = true;
}

void MoveDownTrigger::OnExit()
{
	Trigger::OnExit();
	auto& object = ECS::GetComponent<MoveDown>(m_targetEntities[0]);
	object.moveDown = false;
}
