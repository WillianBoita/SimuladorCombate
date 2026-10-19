# Arena de Combate

Projeto dedicado a criação de uma arena de combate, com vários personagens, processada em turnos.
Será desenvolvida com a metodologia OOP em C++.

## Regras

Possui 2 personagens, Mage e Warrior, ambos herdando uma classe pai Character.
Ao escolher um personagem, o programa escolhe o personagem oposto.
Cada personagem possui uma habilidade e stats distintas.

1. Warrior

+ Vida média, dano alto, cura média.
+ Habilidade: Dano crítico - causa 80% a mais de dano quando a habilidade estiver ativa.
+ A habilidade é ativa em um turno, e dura pelos próximos dois ataques.

2. Mage

+ Vida baixa, dano médio, cura alta.
+ Habilidade: Regeneração - Cura metade do seu valor padrão de cura por vários turnos.
+ A habilidade é ativa em um turno, e dura por 3 turnos, independentemente da escolha de ação do usuário.

O vencedor é decidido quando o oponente tiver vida maior ou igual a 0.
O turno do usuário é calculado por primeiro, em caso de empate, o usuário é prioritário.
