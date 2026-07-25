/*
Practice 6.9.2 - Packed Game Entity (bit-fields)

Problem:
A retro game needs thousands of entities, so each must be TINY:

  struct entity {
      unsigned int alive   : 1;
      unsigned int team    : 2;    // 0..3
      unsigned int hp      : 7;    // 0..127
      unsigned int x       : 10;   // 0..1023
      unsigned int y       : 10;   // 0..1023
      unsigned int facing  : 2;    // 0=N 1=E 2=S 3=W
  };                                // 32 bits of payload!

Implement:
  void e_print(const struct entity *e);   // [T2 hp=100 (512,384) facing=E alive]
  void e_damage(struct entity *e, unsigned dmg);  // hp-=dmg, floor at 0;
                                                  // hp==0 -> alive=0
  void e_move(struct entity *e, int dx, int dy);  // clamp into 0..1023!
  void e_turn_right(struct entity *e);            // N->E->S->W->N (mod 4)

main:
  1. print sizeof(struct entity) vs sizeof an unpacked version (6 ints).
  2. spawn an entity mid-map; move it beyond the edge - show clamping.
  3. damage it in a loop (e.g. 30/hit) until dead; print each state.
  4. turn right 5 times; show facing cycles correctly.
  5. DEMONSTRATE the overflow hazard: what does hp = 130 store? Print it,
     explain in a one-line comment.

DSA/Algorithm Focus: data packing + saturating arithmetic + modular arithmetic
Best approach: damage uses "if (dmg >= e->hp)" BEFORE subtracting (why?);
turn uses (facing + 1) & 3.
Complexity: O(1) everything.
Constraints: clamp logic must handle negative dx/dy since x is unsigned -
compute in a signed temp first!

Hints (Socratic):
- e->hp -= dmg on unsigned fields can't go negative - what DOES it do,
  and why must you compare first?
- Why is (facing + 1) & 3 equivalent to % 4 here? When is & cheaper?
- e_move: what goes wrong with e->x += dx directly when dx = -5 and x = 2?
  Walk through the unsigned arithmetic.
*/

#include <stdio.h>

// Student writes struct here

int main(){
    // Student writes code here
    return 0;
}
