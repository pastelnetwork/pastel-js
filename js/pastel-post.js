Pastel["getRandomValue"] = () => {
    let window_ = 'object' === typeof window ? window : self;
    let crypto_ = typeof window_.crypto !== 'undefined' ? window_.crypto : window_.msCrypto;
    let buf = new Uint32Array(1);
    crypto_.getRandomValues(buf);
    return buf[0] >>> 0;
}