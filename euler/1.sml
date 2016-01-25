(* 1. Multiples of 3 and 5 *)

open Int
open List

fun enum(low, high) =
  if low >= high then []
  else
      low :: enum(low+1, high)

fun solve() =
  foldl (fn (a,b) => a + b)
	0
	(filter (fn x => (rem(x, 3) = 0) orelse (rem(x,5) = 0)) (enum(0, 1000)))
