def f(n)
  res = ''
  while n > 0
    t = (n - 1) % 26
    res += (97 + t).chr

    n -= t;
    n /= 26;
  end

  res.reverse
end

n = gets.to_i
puts f(n)

