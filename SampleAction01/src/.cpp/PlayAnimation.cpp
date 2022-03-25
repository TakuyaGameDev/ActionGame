#include "../.h/PlayAnimation.h"
#include "../.h/Actor/Actor.h"

bool PlayAnimation::operator()(Actor& actor)
{
    actor.AddanimCnt(actor.GetCurrentAnim().GetDuration());

    if (actor.GetanimCnt() >= actor.GetCurrentAnim().GetmaxFrame())
    {    // ���[�v�Đ�����̃A�j���[�V��������
        if (actor.GetCurrentAnim().GetisLoop())
        {
            actor.ResetanimCnt();
        }
        else
        {
            actor.SetanimCnt(actor.GetCurrentAnim().GetmaxFrame() - 1);
            actor.SetisAnimEnd(true);
        }
    }
    return false;
}
