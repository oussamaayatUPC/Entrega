DROP DATABASE IF EXISTS bd;
CREATE DATABASE bd; 

CREATE TABLE `partidas` (
  `NumJugadores` int(11) NOT NULL,
  `id1` varchar(2000) NOT NULL,
  `id2` varchar(2000) NOT NULL,
  `resultado` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;



CREATE TABLE `players` (
  `Id` int(11) NOT NULL,
  `Correo` varchar(25) NOT NULL,
  `Password` varchar(12) NOT NULL,
  `PartidasGanadas` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;



CREATE TABLE `relacion` (
  `id` int(11) NOT NULL,
  `PartidasGanadas` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;



