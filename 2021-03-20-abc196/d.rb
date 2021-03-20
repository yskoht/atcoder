require 'set'

$res = 0

def f(i, ti, ai, bi)
  h = ti.size
  w = ti.first.size

  if ai == 0 and bi == 0
    h.times do |y|
      return unless ti[y].all?
    end

    $res += 1
    return
  end

  y = i / w
  x = i % w
  if ti[y][x]
    f(i + 1, ti, ai, bi)
    return
  end

  if ai > 0
    y1 = y + 1
    if y1 < h and ti[y1][x] == false
      ti[y][x] = ti[y1][x] = true
      f(i + 1, ti, ai - 1, bi)
      ti[y][x] = ti[y1][x] = false
    end

    x1 = x + 1
    if x1 < w and ti[y][x1] == false
      ti[y][x] = ti[y][x1] = true
      f(i + 1, ti, ai - 1, bi)
      ti[y][x] = ti[y][x1] = false
    end
  end

  if bi > 0
    ti[y][x] = true
    f(i + 1, ti, ai, bi - 1)
    ti[y][x] = false
  end
end

h, w, a, b = gets.chomp.split.map(&:to_i)
t = Array.new(h) { Array.new(w, false) }
f(0, t, a, b)
puts $res
