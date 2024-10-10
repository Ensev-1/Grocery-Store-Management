# Grocery-Store-Management
C Program
Ky program sherben per menaxhimin e artikujve, shitjeve dhe furnizimeve ne nje dyqan.

Fillimisht deklarojme strukturat qe na nevojiten per programin qe jane:

1.Struktura e Artikullit- perfshin id artikulli, kategorine, emertimin dhe cmimin.
2.Struktura e Klientit- perfshin id klienti,emri,mbiemri,nr tel.
3.Struktura e Shitjes- perfshin id klienti, id fature, data e shitjes, vlera e fatures dhe nje nenstrukture e perbere nga id sasia dhe cmimi per secilin artikull.
4.Struktura e Furnizmit- perfshin id e furnizmit, daten, vleren totale dhe kodin sasine dhe cmimin per secilin artikull.

Kemi ndertuar nje menu ku ne varesi te shtypjes se butonave 1-8, s ose d, therriten perkatesisht funksionet 1-8, ruajtjen e te dhenave ose daljen nga programi.

Programi eshte i ndertuar mbi 10 funksione kryesore. 



Funx 1 (Regjistrimi i Artikullit) – Kemi kerkuar nga perdoruesi te dhenat mbi produktin, fillimisht ID, ku ID  e kontrollojme ne nje cikel me cdo artikull tjeter nese eshte e njejte, nese id eshte e njejte dalim nga funksioni. Ndryshe vazhdojme te marrim te dhenat e tjera mbi artikullin duke i ruajtur ne pozicionin perkates te struktures.

Funx 2 (Regjistrimi i Klientit) – Kemi kerkuar nga perdoruesi te dhenat mbi klientin ku fillimisht ID, ku ID e kontrollojme ne nje cikel me cdo klient tjeter nese eshte e njejte,nese id eshte e njejte dalim nga funksioni. Ndryshe vazhdojme te marrim te dhenat e tjera mbi klientin duke i ruajtur ne pozicionin perkates te struktures se klientit.

Funx 3 (Furnizim) – Rrisim vleren unike te ID se furnizmit me 1, ruajme daten e furnizimit dhe me pas. Kemi kerkuar nga perdoruesi te dhenat rreth furnizimit ku jemi fokusuar mbi ID e artikullit qe kerkohet per furnizim. ID e artikullit me nje cikel duke kontrolluar cdo id artikulli shikojme nese ekziston. Nese nuk ekziston me pare ajo duhet regjistruar prandaj e njoftojme perdoruesin dhe dalim nga cikli. Perndryshe na kerkohet sasia e produktit qe po furnizojme dhe cmimi. Duke shumzuar sasine me cmimin gjejme dhe vleren e furnizimit. Te dhenat i ruajme ne vektorin e struktures se furnizimit.

Funx 4 (Shitje) –Per shitjen fillimisht kerkojme ID e klientit. Nqs kjo ID nuk ekziston dalim nga cikli. Perndryshe, ruajme kete ID, daten dhe rrisim vleren unike te kodit te fatures me 1. Kerkojme ID e produktit nga perdoruesi. Me ane te nje cikli kontrollojme nga artikulli i pare deri tek i fundit nese ky produkt ekziston. Nese po, kerkojme sasine e produtkit. Nese sasia e kerkuar eshte me e madhe se ajo ne magazine dalim nga funksioni. Perndryshe zbresin kete sasi te kerkuar nga ajo ne magazine. I shtojme vleres se fatures sasine e produktit te blere shumzuar me cmimin. Pyesim nese deshiron te blej serish, nese po cikli perseritet, perndryshe vlerat qe ruajtem deri tani ne vektorin e struktures qendrojne sic jane.

Funx 5 (Gjendje ne magazine) – Per te shfaqur gjendjen ne magazine. Hapim file Artikujt ku kemi ruajtur dhe gjithe artikujt e dyqanit. Me ane te nje cikli printojme ne ekran te gjithe elementet perberes(fjalet) e ketij file. 

Funx 6 (Klientet qe blejne me shume ne vlere) – Per te gjetur kete kemi perdorur disa cikle. Fillimisht nga klienti i pare deri tek i fundit, marrim me rradhe id e tyre. Krahasojme me id e cdo shitje, nese eshte e njejte i shtojme vleren ketij personi ne nje variabel v. Pasi kemi mbledhur vleren e cdo shitje e ruajme vleren ne nje vektor. Keshtu kemi gjetur vleren per cdo klient. Me pas kete vektor e rendisim me ane te SELECTION sort.  Me pas nga elementi i pare i vektorit qe ka vleren me te madhe deri tek i fundit, therrasim serish funksionin e pare per te gjetur id e kujt klienti eshte dhe kur vlerat perputhen e shfaqim kete klient.

Funx 7 (Klientet qe blejne me shpesh) – Per te gjetur klientet qe blejne me shpesh kemi perdorur te njejtat cikle si tek funx 6. Fillimisht nga klienti i pare deri tek i fundit, marrim me rradhe id e tyre. Krahasojme me id e cdo shitje, nese eshte e njejte i shtojme ketij personi ne nje variabel v sa here ka bere blerje. Pasi kemi gjetur sa here ka bere blerjet cdo person ia ruajme vlerat ne nje vektor. Keshtu per cdo klient. Me pas kete vektor e rendisim me ane te SELECTION sort.  Me pas nga elementi i pare i vektorit qe ka shpeshtine me te madhe deri tek i fundit, therrasim serish funksionin e pare per te gjetur id e kujt klienti eshte dhe kur vlerat perputhen e shfaqim kete klient.

Funx 8 (Kerkim artikulli sipas id se artikullit) – Kerkojme nga perdoruesi ID e artikullit. Me pas me ane te nje cikli nga elementi i pare deri tek i fundit kerkojme nese kjo ID perputhet me ID e artikujve. Nese po shfaqim te dhenat per kete produkt. Ndryshe themi qe produkti nuk gjendet ne magazine dhe dalim nga funx.



Funx Lexim te Dhenash (Hedh neper vektoret e strukturave vlerat e ruajtura ne file per artikujt, klientet dhe shitjet) – Sherbejne tre pjese kryesore. Fillimisht hapim file e 1 qe do te jete file i artikujve. Keshtu duke nisur nga artikulli i pare deri tek i fundit lexojme me ane te funksionit fread, te gjithe elementet e struktures per elementin e caktuar, deri ne fund. Te njejten gje bejme dhe per file 2 qe do te jete file i klienteve dhe per file 3 qe do te jete file i shitjeve.

Funx Save (ruan ndryshimet e bera ne artikuj kliente dhe shitje)- Me ane te ketij funksioni pasi kemi regjistruar kliente te rinj, artikuj apo kemi bere shitje. Te gjitha keto ndryshime i paraqesim ne file perkates te artikujve, klienteve dhe shitjeve. Hapim file e pare qe eshte file i artikujve, ku me ane te funksionit fwrite hedhim te gjitha te dhenat e ruajtur mbi vektorin e struktures se artikujve duke mbishkuar ato qe kane qene shkuar me para mqs nisim nga artikulli 1. Te njejten gje bejme dhe per klientet ne file2, dhe per shitjet ne file3.
