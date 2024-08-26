

(* Determine son la liste l est trié *)
let rec est_triee (l:'a list) : bool = 
  match l with
  | [] -> true
  | x::[] -> true
  | x::y::q -> if x>y then false else est_triee (y::q)

(* Prend un elem x et une liste L et renvoie L<= et L> *)
let rec partition_aux (x:'a) (l:'a list) ((acc1,acc2) : (('a list) * ('a list)) ) : (('a list) * ('a list))=
  match l with 
  | [] -> (acc1,acc2)
  | [y] -> if y<x then (List.rev (y::acc1),List.rev acc2) 
  else if y>x then (List.rev acc1,List.rev (y::acc2)) 
  else (List.rev acc1,List.rev acc2)
  | y::q -> if y<x then partition_aux x q (y::acc1, acc2)
  else if y> x then partition_aux x q (acc1, y::acc2) 
  else partition_aux x q (acc1, acc2)

let partition (x:'a) (l:'a list) : (('a list) * ('a list))= partition_aux x l ([],[])

let rec tri_rapide (l:'a list) : 'a list = 
  match l with 
  | [] | [_] -> l 
  | y::q -> let (linf,lsup) = (partition y l) in (* On prend le première element comme pivot *)
  (tri_rapide linf )@ (y::(tri_rapide lsup))


(* Fusion qui fusionne deux listes*)
let rec fusion (l1: 'a list) (l2:'a list) : 'a list = 
  match (l1,l2) with
  | [],_ -> l2
  | _,[] -> l1
  | x::q, y::p -> if x<=y then x::(fusion q (y::p))
  else y::(fusion (x::q) p)

(* Separer deux listes *)
let rec separer (l:'a list) : ('a list * 'a list) = 
	match l with 
	| [] | [_] -> (l, [])
	| x::y::q -> let l1, l2 = separer q in ((x :: l1), (y :: l2))

let rec tri_fusion (l:'a list) : 'a list =
  match l with 
  | [] | [_] -> l
  | _ -> let l1,l2 = (separer l) in
  fusion (tri_fusion l1) (tri_fusion l2)

let test () = 
  assert( est_triee [2;1;3;5;7;6;41] = false);
  assert( est_triee [1;2;3;4;4] = true);
  assert(est_triee (tri_fusion [1;2;54;8;4;6;3;7;9]));
  assert(est_triee (tri_rapide [1;2;54;8;4;6;3;7;9]));
  print_string"Tous les tests ont réussi ! \n";;
