#pragma once

#include <optional>
#include <utility>
#include <variant>

namespace ReturnTypes {

template <typename T> struct Ok {
  T value;

  explicit Ok(T &&v) : value(std::forward<T>(v)) {}
  explicit Ok(const T &value) : value(value) {}

  Ok() = delete;
  Ok &operator=(const Ok &) = delete;
  Ok &operator=(Ok &&) = delete;
  Ok(const Ok &) = delete;

  Ok(Ok &&) = default;
};

template <typename E> struct Err {
  E value;

  explicit Err(E &&v) : value(std::forward<E>(v)) {}
  explicit Err(const E &value) : value(value) {}

  Err() = delete;
  Err &operator=(const Err &) = delete;
  Err &operator=(Err &&) = delete;
  Err(const Err &) = delete;

  Err(Err &&) = default;
};

template <typename T, typename E> class Result {
private:
  std::variant<Ok<T>, Err<E>> m_val;

public:
  Result(Ok<T> &&v) : m_val(std::forward<Ok<T>>(v)) {}
  Result(Err<E> &&e) : m_val(std::forward<Err<E>>(e)) {}

  [[nodiscard]] constexpr auto is_ok() const noexcept -> bool {
    return std::holds_alternative<Ok<T>>(m_val);
  }
  [[nodiscard]] constexpr auto is_error() const noexcept -> bool {
    return std::holds_alternative<Err<E>>(m_val);
  }

  auto get() -> T & { return std::get<Ok<T>>(m_val).value; }

  auto get() const -> const T & { return std::get<Ok<T>>(m_val).value; }

  auto get_error() -> E & { return std::get<Err<E>>(m_val).value; }

  auto get_error() const -> const E & { return std::get<Err<E>>(m_val).value; }
};

// aliasing std::optional
template <typename T> using Option = std::optional<T>;

} // namespace ReturnTypes
