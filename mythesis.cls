\ProvidesClass{mythesis}
%% For normal draft builds

\LoadClass[noroman,nobind,twoside]{hepthesis}

%\LoadClass[noroman,hyperpdf,nobind,sftitles,oneside]{hepthesis}
%\LoadClass[noroman,hyperpdf,nobind,draft,sftitles,oneside]{../../../style/hepthesis}
%\LoadClass[noroman,hyperpdf,nobind,draft,twoside]{../../../style/hepthesis}
%\LoadClass[noroman,hyperpdf,bindnopdf]{hepthesis}

%\LoadClass[noroman,hyperpdf,nobind,draft,sftitles,oneside,hidefront]{hepthesis}
%% For short draft builds (breaks citations by necessity)
%\LoadClass[noroman,hyperpdf,nobind,draft,hidefrontback]{hepthesis}
%% For Cambridge soft-bound version 
%\LoadClass[noroman,hyperpdf,bindnopdf]{hepthesis}
%% For Cambridge hard-bound version (must be one-sided)
%\LoadClass[noroman,hyperpdf,oneside]{hepthesis}

%% ------------------------------------- %% Standard packages %% ------------------------------------- 
\RequirePackage{cite} 
%\RequirePackage{morefloats} 
\RequirePackage{mathrsfs} % script font 
\RequirePackage{afterpage}
%% Using Babel allows other languages to be used and mixed-in easily
\RequirePackage[ngerman,english]{babel}
\selectlanguage{english}
%% Quotes in different languages are different.
%% Using \enquote{bla} automatically uses the correct quotes
%% according to the Babel language that is set 
\RequirePackage[babel]{csquotes}
%% Subfigures - note subfig is incompatible with ccaption 
\RequirePackage{subfigure}
%% TikZ is a marvellous drawing package
\RequirePackage{tikz}

\RequirePackage{overpic}

\setcounter{secnumdepth}{3} %override hepthesis - want subsubsecs numbered

% General table packages
\usepackage{multirow}
\usepackage{rotating}
\usepackage{pbox}
\usepackage{multirow}
% For aligning numbers in tables by decimal point
\usepackage{dcolumn}
% Following is so can draw horizontal dashed lines in tables. For some reason need to
% include array to stop undefined reference when using arydshln
\usepackage{array}
%\usepackage{arydshln}
