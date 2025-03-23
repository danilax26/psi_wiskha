// © 03/2025Daniel Talberg. Все права защищены.
// Этот код не может быть скопирован и/или распространен без разрешения автора.

class PsiTowerRecipe extends RecipeBase
{
    override void Init()
    {
        m_Name = "Собрать пси-вышку";
        m_IsInstaRecipe = false;
        m_AnimationLength = 5.0;
        m_Specialty = 0.02;

        InsertIngredient(0, "MetalPlate"); // 1x металлическая пластина
        InsertIngredient(1, "WoodenPlank"); // 2x деревянные доски
        InsertIngredient(2, "ElectronicParts"); // 1x электроника

        AddResult("PsiTower");
    }
}