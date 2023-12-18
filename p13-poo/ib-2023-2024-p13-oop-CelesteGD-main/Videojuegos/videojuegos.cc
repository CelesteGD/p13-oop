/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Celeste González Díaz
 * @date 1i8 Dec 2023
 * @contact alu0101648361@ull.edu.es
 * @brief main function of our program
 */

#include <iostream>
#include <string>

// Interfaz Entregable
class Entregable {
public:
    virtual void entregar() = 0;
    virtual void devolver() = 0;
    virtual bool isEntregado() const = 0;
    virtual int compareTo(const Entregable& otro) const = 0;
};

// Clase Serie
class Serie : public Entregable {
private:
    std::string titulo;
    int numTemporadas;
    bool entregado;
    std::string genero;
    std::string creador;

public:
    Serie();
    Serie(const std::string& titulo, const std::string& creador);
    Serie(const std::string& titulo, int numTemporadas, const std::string& genero, const std::string& creador);

    // Métodos get y set
    const std::string& getTitulo() const;
    int getNumTemporadas() const;
    const std::string& getGenero() const;
    const std::string& getCreador() const;

    void setTitulo(const std::string& titulo);
    void setNumTemporadas(int numTemporadas);
    void setGenero(const std::string& genero);
    void setCreador(const std::string& creador);

    // Métodos de la interfaz Entregable
    void entregar() override;
    void devolver() override;
    bool isEntregado() const override;
    int compareTo(const Entregable& otro) const override;

    // Método toString
    std::string toString() const;
};

// Clase Videojuego
class Videojuego : public Entregable {
private:
    std::string titulo;
    int horasEstimadas;
    bool entregado;
    std::string genero;
    std::string compania;

public:
    Videojuego();
    Videojuego(const std::string& titulo, int horasEstimadas);
    Videojuego(const std::string& titulo, int horasEstimadas, const std::string& genero, const std::string& compania);

    // Métodos get y set
    const std::string& getTitulo() const;
    int getHorasEstimadas() const;
    const std::string& getGenero() const;
    const std::string& getCompania() const;

    void setTitulo(const std::string& titulo);
    void setHorasEstimadas(int horasEstimadas);
    void setGenero(const std::string& genero);
    void setCompania(const std::string& compania);

    // Métodos de la interfaz Entregable
    void entregar() override;
    void devolver() override;
    bool isEntregado() const override;
    int compareTo(const Entregable& otro) const override;

    // Método toString
    std::string toString() const;
};

// Implementación de las clases y la interfaz Entregable
// ...

// Aplicación ejecutable
int main() {
    Serie series[5];
    Videojuego videojuegos[5];

    // Crear objetos en cada posición del array
    series[0] = Serie("Breaking Bad", 5, "Drama", "Vince Gilligan");
    series[1] = Serie("Game of Thrones", 8, "Fantasy", "David Benioff");
    series[2] = Serie("Stranger Things", 4, "Science Fiction", "Duffer Brothers");

    videojuegos[0] = Videojuego("The Legend of Zelda", 30, "Adventure", "Nintendo");
    videojuegos[1] = Videojuego("Red Dead Redemption 2", 50, "Action-Adventure", "Rockstar Games");

    // Entregar algunos Videojuegos y Series
    series[0].entregar();
    series[1].entregar();
    videojuegos[0].entregar();

    // Contar Series y Videojuegos entregados
    int numSeriesEntregadas = 0;
    int numVideojuegosEntregados = 0;

    for (const auto& serie : series) {
        if (serie.isEntregado()) {
            ++numSeriesEntregadas;
        }
    }

    for (const auto& videojuego : videojuegos) {
        if (videojuego.isEntregado()) {
            ++numVideojuegosEntregados;
        }
    }

    std::cout << "Series entregadas: " << numSeriesEntregadas << std::endl;
    std::cout << "Videojuegos entregados: " << numVideojuegosEntregados << std::endl;

    // Encontrar Videojuego con más horas estimadas
    int maxHorasEstimadas = 0;
    Videojuego videojuegoMaxHoras;

    for (const auto& videojuego : videojuegos) {
        if (videojuego.getHorasEstimadas() > maxHorasEstimadas) {
            maxHorasEstimadas = videojuego.getHorasEstimadas();
            videojuegoMaxHoras = videojuego;
        }
    }

    // Encontrar Serie con más temporadas
    int maxTemporadas = 0;
    Serie serieMaxTemporadas;

    for (const auto& serie : series) {
        if (serie.getNumTemporadas() > maxTemporadas) {
            maxTemporadas = serie.getNumTemporadas();
            serieMaxTemporadas = serie;
        }
    }

    // Mostrar la información
    std::cout << "Videojuego con más horas estimadas: " << videojuegoMaxHoras.toString() << std::endl;
    std::cout << "Serie con más temporadas: " << serieMaxTemporadas.toString() << std::endl;

    return 0;
}

