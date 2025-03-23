// © 03/2025Daniel Talberg. Все права защищены.
// Этот код не может быть скопирован и/или распространен без разрешения автора.
// PsiTowerEffect.c

class PsiTower extends ItemBase
{
    private bool m_IsActive = false;
    private float m_AffectRadius = 50.0;
    private ref Timer m_Timer;
    
    void PsiTower()
    {
        m_Timer = new Timer;
        m_Timer.Run(1.0, this, "CheckForPlayers", NULL, true);
    }

    void CheckForPlayers()
    {
        if (!m_IsActive) return;

        array<PlayerBase> players = new array<PlayerBase>;
        GetGame().GetPlayers(players);

        foreach (PlayerBase player : players)
        {
            if (vector.Distance(player.GetPosition(), GetPosition()) <= m_AffectRadius)
            {
                ApplyPsiEffect(player);
            }
        }
    }

    void ApplyPsiEffect(PlayerBase player)
    {
        float health = player.GetHealth("GlobalHealth", "Health");
        float blood = player.GetHealth("GlobalHealth", "Blood");

        player.SetHealth("GlobalHealth", "Health", health * 0.99); // -1%
        player.SetHealth("GlobalHealth", "Blood", blood * 0.99);   // -1%
    }

    void Activate()
    {
        m_IsActive = true;
    }

    void Deactivate()
    {
        m_IsActive = false;
    }
}