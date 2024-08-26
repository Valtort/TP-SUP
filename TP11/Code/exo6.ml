type expr = 
  | Const of float (* Cste*)
  | Add of expr * expr (* Add(e1,e2) correspond à e1 + e2*)
  | Mult of expr*expr
  | Var of string
  | IFTE of boolexpr * expr * expr (* if b then e1 else e2*)
and boolexpr = 
  | BConst of bool
  | Or of boolexpr*boolexpr
  | And of boolexpr*boolexpr
  | Not of boolexpr 
  | Eq of expr*expr
  | Leq of expr*expr (*inférieur ou égal*)


type context = (string*float) list

(* Evalue une expression *)
let rec eval (e:expr) (c:context): float =
  match e with 
  | Const x -> x
  | Add (e1,e2) -> eval e1 c +. eval e2 c
  | Mult (e1,e2) -> eval e1 c *. eval e2 c
  | Var x -> get_var x c
  | IFTE (b1,e1,e2) -> if eval_bool b1 c = true then (eval e1 c) else (eval e2 c)
and eval_bool (b:boolexpr) (c:context) : bool = 
  match b with 
  | BConst x -> x
  | Or (b1,b2) -> (eval_bool b1 c) || (eval_bool b2 c)
  | And (b1,b2) -> (eval_bool b1 c) && (eval_bool b2 c)
  | Not b1 -> not (eval_bool b1 c)
  | Eq (b1,b2) -> (eval b1 c) = (eval b2 c)
  | Leq (b1,b2) -> (eval b1 c) <= (eval b2 c)
  
(* Récupère la valeur d'une variable booléenne dans le contexte *)
let rec get_var (s:string) (c:context) : float =
  match c with 
  | [] -> failwith"La variable n'est pas dans le contexte"
  | (a,n )::q -> if a = s then n else get_var s q

(* Compte le nb d'occurences d'une variable dans une expression *)
let rec var_count (e:expr) (v:string) : int =
  match e with
  | Const _ -> 0
  | Var x -> if x =v then 1 else 0
  | Add (e1,e2) | Mult (e1,e2) -> var_count e1 v + var_count e2 v
  | IFTE (b,e1,e2) -> var_count_bool b v + var_count e1 v + var_count e2 v

(* Compte le nombre d'occurence d'une variable dans une expression booléenne *)
and var_count_bool (b:boolexpr) (v:string) : int =
  match b with
  | BConst  _ -> 0
  | Not bb -> var_count_bool bb v
  | And (b1,b2) | Or (b1,b2) -> var_count_bool b1 v + var_count_bool b2 v
  | Eq (e1,e2) | Leq (e1,e2) -> var_count e1 v + var_count e2 v